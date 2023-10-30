.SILENT: test
.SILENT: test_expr_base
.SILENT: parser
.SILENT: clean
.SILENT: test_parser
.SILENT: test_parser_only

yellow = echo $(2) "\033[01;33m$(1)\033[01;0m"
green = echo $(2) "\033[01;32m$(1)\033[01;0m"
red = echo $(2) "\033[01;31m$(1)\033[01;0m"

parser:
	$(call yellow,Building parser,-n)
	yacc -d src/lexer/parser.y -o src/lexer/y.tab.c
	lex -o src/lexer/lex.yy.c src/lexer/lexer.l
	gcc src/lexer/y.tab.c src/lexer/lex.yy.c -o bin/parser -ll
	$(call green, DONE)
	echo

test: test_expr_base

test_expr_base:
	$(call yellow,Testing expr_base)
	g++ src/conversion/expr_base.cpp tests/test_expr_base.cpp -Iinclude/ -o bin/test_expr_base
	./bin/test_expr_base
	$(call green,expr_base test passed)
	echo

test_parser: parser test_parser_only

test_parser_only:
	$(call yellow,Testing parser)
	$(call yellow,Testing at polymultiply.lg,-n)
	./bin/parser examples/polymultiply.lg tests/tokens/polymultiply_tokens.txt tests/parsed/polymultiply_parsed.lg > /dev/null && $(call green, \tOK) || $(call red, \tFailed)
	$(call yellow,Testing at find_the_roots.lg,-n)
	./bin/parser examples/find_the_roots.lg tests/tokens/find_the_roots_tokens.txt tests/parsed/find_the_roots_parsed.lg > /dev/null && $(call green, \tOK) || $(call red, \tFailed)
	$(call yellow,Testing at differentiate.lg,-n)
	./bin/parser examples/differentiate.lg tests/tokens/differentiate_tokens.txt tests/parsed/differentiate_parsed.lg > /dev/null && $(call green, \tOK) || $(call red, \tFailed)
	$(call yellow,Testing at other_funcs.lg,-n)
	./bin/parser examples/other_funcs.lg tests/tokens/other_funcs_tokens.txt tests/parsed/other_funcs_parsed.lg > /dev/null && $(call green, \tOK) || $(call red, \tFailed)
	$(call yellow,Testing at test_parser.lg,-n)
	./bin/parser tests/test_parser.lg tests/tokens/test_parser_tokens.txt tests/parsed/test_parser_parsed.lg > /dev/null && $(call green, \tOK) || $(call red, \tFailed)

clean:
	rm -rf bin/*
