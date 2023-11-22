.SILENT: test
.SILENT: test_expr_base
.SILENT: parser
.SILENT: clean
.SILENT: test_parser
.SILENT: test_parser_only
.SILENT: test_symtab
.SILENT: test_complex
.SILENT: test_code_gen

yellow = echo $(2) "\033[01;33m$(1)\033[01;0m"
green = echo $(2) "\033[01;32m$(1)\033[01;0m"
red = echo $(2) "\033[01;31m$(1)\033[01;0m"

test_parser_at = $(call yellow,Testing at $(1),-n); ./bin/parser $(1) -l tests/tokens/$(2) -p tests/parsed/$(3) -c tests/cpp_out/$(4) > tests/logs/$(5) && $(call green, \tOK) || $(call red, \tFailed)

create_folders:
	@mkdir -p bin tests/parsed tests/tokens tests/logs tests/cpp_out

parser: create_folders
	$(call yellow,Building parser,-n)
	yacc -d src/parser/parser.y -o src/parser/y.tab.c
	mv src/parser/y.tab.h include/y.tab.h
	lex -o src/lexer/lex.yy.c src/lexer/lexer.l
	gcc -g src/parser/y.tab.c src/lexer/lex.yy.c src/semantic/symbol_table.c -o bin/parser -Iinclude
	$(call green, DONE)
	echo

test: create_folders test_expr_base

test_expr_base: create_folders
	$(call yellow,Testing expr_base)
	g++ -std=c++20 -g lib/expr_base.cpp tests/test_expr_base.cpp -Iinclude/ -o bin/test_expr_base
	./bin/test_expr_base
	$(call green,expr_base test passed)
	echo

test_complex: create_folders
	$(call yellow,Testing complex)
	g++ -std=c++20 -g lib/expr_base.cpp  tests/test_complex.cpp -Iinclude/ -o bin/test_complex
	./bin/test_complex
	$(call green,complex test passed)
	echo

test_parser: create_folders parser test_parser_only

test_parser_only: create_folders
	$(call yellow,Testing parser)
	$(call test_parser_at,examples/polymultiply.lg,polymultiply_tokens.txt,polymultiply_parsed.lg,polymultiply.cpp,polymultiply_log.txt)
	$(call test_parser_at,examples/find_the_roots.lg,find_the_roots_tokens.txt,find_the_roots_parsed.lg,find_the_roots.cpp,find_the_roots_log.txt)
	$(call test_parser_at,examples/differentiate.lg,differentiate_tokens.txt,differentiate_parsed.lg,differentiate.cpp,differentiate_log.txt)
	$(call test_parser_at,examples/other_funcs.lg,other_funcs_tokens.txt,other_funcs_parsed.lg,other_funcs.cpp,other_funcs_log.txt)
	$(call test_parser_at,tests/test_parser.lg,test_parser_tokens.txt,test_parser_parsed.lg,test_parser.cpp,test_parser_log.txt)
	$(call test_parser_at,tests/test_semantic.lg,test_semantic_tokens.txt,test_semantic_parsed.lg,test_semantic.cpp,test_semantic_log.txt)
	$(call test_parser_at,tests/test_codegen.lg,test_codegen_tokens.txt,test_codegen_parsed.lg,test_codegen.cpp,test_codegen_log.txt)

test_code_gen: create_folders parser
	$(call yellow,Testing code generation)
	$(call test_parser_at,examples/polymultiply.lg,polymultiply_tokens.txt,polymultiply_parsed.lg,polymultiply.cpp,polymultiply_log.txt)
	g++ -std=c++20 -g -Iinclude tests/cpp_out/polymultiply.cpp lib/expr_base.cpp -o bin/polymultiply
	./bin/polymultiply
	$(call green,Code generation test passed)
	echo

test_symtab: create_folders
	$(call yellow,Testing symbol table)
	gcc tests/test_symtab.c src/semantic/symbol_table.c -o bin/test_symtab -Iinclude
	./bin/test_symtab && $(call green,Symbol table test passed) || $(call red,Symbol table test failed)

clean:
	rm -rf bin/* tests/parsed/* tests/tokens/* tests/logs/* src/parser/y.tab.c src/lexer/lex.yy.c include/y.tab.h
