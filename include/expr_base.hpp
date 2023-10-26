#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;


enum Type {
    CONSTANT,
    FUNCTION,
    OPERATOR,
    SYMBOL,
};


enum Operator {
    NO_OPERATOR,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
};


enum Function {
    NO_FUNCTION,
    GIF,  // Greatest Integer Function
    SIF,  // Smallest Integer Function
    ABS,  // absolute value
    SIN,
    COS,
    TAN,
    COSEC,
    SEC,
    COT,
};


class BadSymbolException: public std::exception{
    public:
    BadSymbolException();
    BadSymbolException(std::string);
};


class BugException: public std::exception{
    public:
        BugException();
        BugException(std::string);
};


class Expression {
    private:
    std::string value;
    vector<Expression> exprs;
    Type type;
    Operator op;
    Function func;
    double pow;
    double coeff;
    double degree;

    public:
    int test;

    // Initialisers
    Expression();
    Expression(std::string);
    Expression(double);
    Expression(std::string, double);
    Expression(Operator);
    Expression(Function, std::string);
    Expression(Function, Expression);

    // public static variables
    static map<Operator, std::string> operators;
    static map<Function, std::string> functions;

    // functions
    void init();
    std::vector<Expression, std::allocator<Expression>>::const_iterator begin();
    std::vector<Expression, std::allocator<Expression>>::const_iterator end();
    int push(Expression&, void (*)(int, vector<Expression>&));
    void push_all(Expression&, void (*)(int, vector<Expression>&));
    std::string getValue();
    double getCoeff();
    Type getType();
    Operator getOperator();
    Function getFunction();
    std::size_t size();
    void simplify();
    bool ltWithoutFunc(Expression&);
    void validate_symbol(std::string);
    double getDegree();

    // operator overloads
    friend ostream& operator<<(ostream&, const Expression&);
    friend std::string operator<<(std::string, const Expression&);
    Expression operator+(Expression);
    Expression operator+(double);
    friend Expression operator+(double, Expression);
    Expression operator-();
    Expression operator-(Expression);
    Expression operator-(double);
    friend Expression operator-(double, Expression);
    Expression operator*(Expression);
    Expression operator*(double);
    friend Expression operator*(double, Expression);
    Expression operator/(Expression);
    Expression operator/(double);
    friend Expression operator/(double, Expression);
    bool operator==(Expression);
    bool operator==(double);
    friend bool operator==(double, Expression);
    bool operator!=(Expression);
    bool operator!=(double);
    friend bool operator!=(double, Expression);
    bool operator<(Expression);
    bool operator<(double);
    friend bool operator<(double, Expression);
    Expression operator[](int);

    // other friend functions
    friend void after_push_plus(int, vector<Expression>&);
    friend void after_push_mult(int, vector<Expression>&);
    friend bool eq_without_pow(Expression, Expression, bool);
    friend Expression fix_singlet(Expression);
    friend Expression multiply(Expression, Expression, bool);
    friend bool is_equal(Expression, Expression, bool);
    friend void cancel_commons(Expression&, Expression&, Expression&, bool);

    void convert_sum_of_divs_to_single_div();
};


/*
TODO: Create a class for these functions as some of them would 
conflict with standard math functions
*/
// functions
Expression gif(const Expression&);
Expression sif(const Expression&);
Expression sin(const Expression&);
Expression cos(const Expression&);
Expression tan(const Expression&);
Expression cosec(const Expression&);
Expression sec(const Expression&);
Expression cot(const Expression&);
