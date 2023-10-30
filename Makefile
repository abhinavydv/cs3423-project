.SILENT: test
.SILENT: test_expr_base
.SILENT: parser
.SILENT: clean
.SILENT: test_parser

yellow = echo "\033[01;33m$(1)\033[01;0m"
green = echo "\033[01;32m$(1)\033[01;0m"
red = echo "\033[01;31m$(1)\033[01;0m"

parser:
	$(call yellow, "Building parser")
	yacc -d src/lexer/parser.y -o src/lexer/y.tab.c
	lex -o src/lexer/lex.yy.c src/lexer/lexer.l
	gcc src/lexer/y.tab.c src/lexer/lex.yy.c -o bin/parser -ll
	$(call green, "Parser built")
	echo

test: test_expr_base

test_expr_base:
	$(call yellow, "Testing expr_base")
	g++ src/conversion/expr_base.cpp tests/test_expr_base.cpp -Iinclude/ -o bin/test_expr_base
	./bin/test_expr_base
	$(call green, "expr_base test passed")
	echo

test_parser: parser
	$(call yellow, "Testing parser")
	./bin/parser examples/polymultiply.lg tests/parsed.txt
	$(call green, "Parser test passed")
	echo

clean:
	rm -rf bin/*
