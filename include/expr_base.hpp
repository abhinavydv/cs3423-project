#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <complex>

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


class BadSymbolException: public exception{
    public:
    BadSymbolException();
    BadSymbolException(string);
};


class NotDifferentiableException: public exception{
    public:
    NotDifferentiableException();
    NotDifferentiableException(string);
};


class BugException: public exception{
    public:
        BugException();
        BugException(string);
};


class Complex {
    private:
    double real;
    double imag;

    public:
    Complex();
    Complex(complex<double>);
    Complex(double);
    Complex(double, double);
    double getReal();
    double getImag();
    double normsq();
    Complex conjugate();
    Complex operator+(Complex);
    Complex operator+(double);
    friend Complex operator+(double, Complex); // what it will do
    Complex operator+=(Complex);
    Complex operator+=(double);
    Complex operator-(); 
    Complex operator-(Complex);
    Complex operator-(double);
    friend Complex operator-(double, Complex);
    Complex operator-=(Complex);
    Complex operator-=(double);
    Complex operator*(Complex);
    Complex operator*(double);
    friend Complex operator*(double, Complex);
    Complex operator*=(Complex);
    Complex operator*=(double);
    Complex operator/(Complex);
    Complex operator/(double);
    friend Complex operator/(double, Complex);
    Complex operator/=(Complex);
    Complex operator/=(double);
    Complex operator^(double);
    Complex operator^=(double);
    bool operator==(Complex);
    bool operator==(double);
    friend bool operator==(double, Complex);
    bool operator!=(Complex);
    bool operator!=(double);
    friend bool operator!=(double, Complex);
    bool operator<(Complex);
    bool operator<(double);
    friend bool operator<(double, Complex);
    bool operator>(Complex);
    bool operator>(double);
    friend bool operator>(double, Complex);
    bool operator<=(Complex);
    bool operator<=(double);
    friend bool operator<=(double, Complex);
    bool operator>=(Complex);
    bool operator>=(double);
    friend bool operator>=(double, Complex);
    friend ostream& operator<<(ostream&, const Complex&);
    friend string operator<<(string, const Complex&);

};


class Expression {
    private:
    string value;
    vector<Expression> exprs;
    Type type;
    Operator op;
    Function func;
    double power;
    Complex coeff;
    double degree;

    public:
    int test;

    // Initialisers
    Expression();
    Expression(string);
    Expression(double);
    Expression(Complex);
    Expression(string, Complex);
    Expression(Operator);
    Expression(Function, string);
    Expression(Function, Expression);

    // public static variables
    static map<Operator, string> operators;
    static map<Function, string> functions;

    // functions
    void init();
    vector<Expression, allocator<Expression>>::const_iterator begin();
    vector<Expression, allocator<Expression>>::const_iterator end();
    int push(Expression&, void (*)(int, vector<Expression>&));
    void push_all(Expression&, void (*)(int, vector<Expression>&));
    string getValue();
    Complex getCoeff();
    Type getType();
    Operator getOperator();
    Function getFunction();
    size_t size();
    void simplify();
    bool ltWithoutFunc(Expression&);
    void validate_symbol(string);
    double getDegree();
    template <typename T> Expression reduce(const T, Expression);
    Expression evaluate(map<string, Expression>);
    Expression differentiate(Expression);
    Expression differentiate(string);
    Expression differentiate(Expression, int);
    Expression differentiate(string, int);

    // operator overloads
    friend ostream& operator<<(ostream&, const Expression&);
    friend string operator<<(string, const Expression&);
    Expression operator+(Expression);
    // Expression operator+(Complex);
    friend Expression operator+(Complex, Expression);
    Expression operator+=(Expression);
    Expression operator-();
    Expression operator-(Expression);
    // Expression operator-(Complex);
    friend Expression operator-(Complex, Expression);
    Expression operator*(Expression);
    // Expression operator*(Complex);
    friend Expression operator*(Complex, Expression);
    Expression operator/(Expression);
    Expression operator/(Complex);
    friend Expression operator/(Complex, Expression);
    Expression operator^(double);
    Expression operator^=(double);
    Expression operator()(map<string, Expression>);
    bool operator==(Expression);
    bool operator==(Complex);
    friend bool operator==(Complex, Expression);
    bool operator!=(Expression);
    bool operator!=(Complex);
    friend bool operator!=(Complex, Expression);
    bool operator<(Expression);
    bool operator<(Complex);
    friend bool operator<(Complex, Expression);
    Expression operator[](int);

    // other friend functions
    friend void after_push_plus(int, vector<Expression>&);
    friend void after_push_mult(int, vector<Expression>&);
    friend bool eq_without_pow(Expression, Expression, bool);
    friend Expression fix_singlet(Expression);
    friend Expression multiply(Expression, Expression, bool);
    friend bool is_equal(Expression, Expression, bool);
    friend void cancel_commons(Expression&, Expression&, Expression&, bool);
    friend Expression remove_zeroes(Expression);
    void convert_sum_of_divs_to_single_div();
};


// functions
Expression sin(Expression);
Expression cos(Expression);
Expression tan(Expression);
Expression cosec(Expression);
Expression sec(Expression);
Expression cot(Expression);
Expression floor(Expression);
Expression ceil(Expression);
Expression abs(Expression);
Expression sum(vector<Expression>);

Complex sin(Complex);
Complex cos(Complex);
Complex tan(Complex);
Complex cosec(Complex);
Complex sec(Complex);
Complex cot(Complex);
Complex floor(Complex);
Complex ceil(Complex);
Complex abs(Complex);
Complex pow(Complex, Complex);

string without_trail_0(Complex val);

int factorial(int);
