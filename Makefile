.SILENT: test
.SILENT: test_expr_base

test: test_expr_base

test_expr_base:
	echo "Testing expr_base"
	g++ src/expr_base.cpp tests/test_expr_base.cpp -Iinclude/ -o bin/test_expr_base
	./bin/test_expr_base
	echo "\033[01;32mexpr_base Test passed\033[01;0m"

