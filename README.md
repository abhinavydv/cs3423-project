# cs3423-project
Project for Compilers - II Course at IITH

### Problem statement
- Making a language that
    - supports symbolic mathematical expressions.
    - Supports evaluation and differentation of expression.
- **Why?**
    - To make a language that can be used to solve mathematical problems.
    - Creation of a user-friendly and intuitive language for curves.
    - Increased accuracy and efficiency in performing polynomial computations.
    - Simplification of complex polynomial expressions and equations.

### Difficulties
- Designing the symbol table.
- Expression manipulation and differentiation.
- Managing a class vector inside a language with no classes.

### Build
- To build the project, run  
    ```
    $ make parser
    ```

### Run
- To run the code, run  
    ```
    $ ./bin/parser <input code> -l <output lexer file> -p <output parser file> -c <output cpp code file>
    $ g++ <output cpp code file> -Iinclude lib/expr_base.cpp -o <output executable file>
    $ ./<output executable file>
    ```
- for ex:  
    ```
    $ ./bin/parser test/test1.txt -l test/test1_lexer.txt -p test/test1_parser.txt -c test/test1.cpp
    $ g++ test/test1.cpp -Iinclude lib/expr_base.cpp -o test/test1
    $ ./test/test1
    ```

