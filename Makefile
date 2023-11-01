.SILENT: test
.SILENT: test_expr_base
.SILENT: parser
.SILENT: clean
.SILENT: test_parser
.SILENT: test_parser_only

yellow = echo $(2) "\033[01;33m$(1)\033[01;0m"
green = echo $(2) "\033[01;32m$(1)\033[01;0m"
red = echo $(2) "\033[01;31m$(1)\033[01;0m"

test_parser_at = $(call yellow,Testing at $(1),-n); ./bin/parser $(1) tests/tokens/$(2) tests/parsed/$(3) > /dev/null && $(call green, \tOK) || $(call red, \tFailed)

create_folders:
	@mkdir -p bin tests/parsed tests/tokens

parser: create_folders
	$(call yellow,Building parser,-n)
	yacc -d src/parser/parser.y -o src/parser/y.tab.c
	mv src/parser/y.tab.h include/y.tab.h
	lex -o src/lexer/lex.yy.c src/lexer/lexer.l
	gcc src/parser/y.tab.c src/lexer/lex.yy.c -o bin/parser -Iinclude
	$(call green, DONE)
	echo

test: create_folders test_expr_base

test_expr_base: create_folders
	$(call yellow,Testing expr_base)
	g++ src/conversion/expr_base.cpp tests/test_expr_base.cpp -Iinclude/ -o bin/test_expr_base
	./bin/test_expr_base
	$(call green,expr_base test passed)
	echo

test_parser: create_folders parser test_parser_only

test_parser_only: create_folders
	$(call yellow,Testing parser)
	$(call test_parser_at,examples/polymultiply.lg,polymultiply_tokens.txt,polymultiply_parsed.lg)
	$(call test_parser_at,examples/find_the_roots.lg,find_the_roots_tokens.txt,find_the_roots_parsed.lg)
	$(call test_parser_at,examples/differentiate.lg,differentiate_tokens.txt,differentiate_parsed.lg)
	$(call test_parser_at,examples/other_funcs.lg,other_funcs_tokens.txt,other_funcs_parsed.lg)
	$(call test_parser_at,tests/test_parser.lg,test_parser_tokens.txt,test_parser_parsed.lg)

clean:
	rm -rf bin/* tests/parsed/* tests/tokens/* src/parser/y.tab.c src/lexer/lex.yy.c include/y.tab.h
