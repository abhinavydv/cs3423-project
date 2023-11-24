# cs3423-project
Project for Compilers - II Course at IITH

### Team Members
- [Abhinav Yadav - CS21BTECH11002](https://github.com/AbhinavYdv)
- [Harsh Goyal - CS21BTECH11020](https://github.com/wetleaf)
- [Jayachandra Naidu - CS21BTECH11050](https://github.com/rootc-jc)
- [Ujjwal Kumar - CS23BTNSK11002](https://github.com/champ-ujjwal)

### Problem statement
- Making a language that
    - supports symbolic mathematical expressions.
    - Supports evaluation and differentation of expression.
- **Why?**
    - To make a language that can be used to solve mathematical problems.
    - Creation of a user-friendly and intuitive language for curves.
    - Simplification of complex polynomial expressions and equations.

### Difficulties
- Designing the symbol table.
- Expression manipulation and differentiation.
- Managing a class vector inside a language with no classes.
- Type checking for types that are convertible. For ex: int is convertible to curve but not vice versa.

### Future Scope
- This is a bare minimum implementation of the language. There are many features that can be added to the language.
- **In built functions**: There are a very few in built functions in the language.
- **Import statements**: Importing other files in the language can be added.

### Build
- To build the compiler, run the following in the project directory that has the `Makefile`:
    ```
    $ make parser
    ```
    This will store the compiler executable in `bin/parser`

### Run
- To run the compiler, run the following in the project directory that has the `Makefile`:
    ```
    $ ./bin/parser <input code> -l <output lexer file> -p <output parser file> -c <output cpp code file>
    $ g++ <output cpp code file> -Iinclude lib/expr_base.cpp -o <output executable file>
    $ ./<output executable file>
    ```
- You can omit the `-l`, `-p` and `-c` flags in the first command if you don't want to store the lexer, parser and cpp code files respectively.
- If not input file is given, the compiler will take input from stdin.
- if -c flag is not given, the compiler will print the output to stdout.
- for ex:  
    ```
    $ ./bin/parser test/test1.txt -l test/test1_lexer.txt -p test/test1_parser.txt -c test/test1.cpp
    $ g++ -std=c++20 test/test1.cpp -Iinclude lib/expr_base.cpp -o test/test1
    $ ./test/test1
    ```

