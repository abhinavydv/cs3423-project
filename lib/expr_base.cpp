#include "expr_base.hpp"
#include <algorithm>
#include <math.h>


using namespace std;


BadSymbolException::BadSymbolException(){
    cout << "\033[01;31mError:\033[01;0m Used prohibited characters in symbol" << endl;
};


BadSymbolException::BadSymbolException(std::string message){
    cout << message << endl;
}


NotDifferentiableException::NotDifferentiableException(){
    cout << "\033[01;31mError:\033[01;0m Expression is not differentiable" << endl;
}


NotDifferentiableException::NotDifferentiableException(std::string message){
    cout << message << endl;
}


BugException::BugException(){
    cout << "\033[01;31mError:\033[01;0m A creepy bug!";
}


BugException::BugException(std::string message){
    cout << message << endl;
}


map<Operator, std::string> Expression::operators = {
    {PLUS, "+"},
    {MULTIPLY, "*"},
    {DIVIDE, "/"},
};

map<Function, std::string> Expression::functions = {
    {SIN, "sin"},
    {COS, "cos"},
    {TAN, "tan"},
    {COSEC, "cosec"},
    {SEC, "sec"},
    {COT, "cot"},
    {GIF, "gif"},
    {SIF, "sif"},
    {ABS, "abs"},
};


// returns string representation of the double val without trailing 0
std::string without_trail_0(double val){
    std::string str = std::to_string(val);
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);

    if (str.back()=='.')
        return str.erase(str.find('.'));

    return str;
}


string without_trail_0(Complex val){
    string real = without_trail_0(val.getReal());
    string imag = without_trail_0(val.getImag());
    if (imag != "0" && imag != "-0")
        return real + "+" + imag + "i";
    return real;
}


// check if the symbol to be used is a valid symbol or not
void Expression::validate_symbol(std::string value){
    for (char chr: value){
        if (chr < 65 || chr > 122 || (chr > 90 && chr < 97))
            throw BadSymbolException();
    }
}


// check if an expression has a single expression as its child.
// if yes then return the child expression
Expression fix_singlet(Expression expr){
    if (expr.size() == 1 && expr.func == NO_FUNCTION){
        Expression exp = expr[0];
        exp.coeff *= expr.coeff;
        exp.power *= expr.power;
        return fix_singlet(exp);
    }
    return expr;
}


Expression::Expression(){
    this->init();
}


Expression::Expression(std::string value){
    this->validate_symbol(value);
    this->init();
    this->value = value;
}


Expression::Expression(double val){
    this->init();
    this->type = CONSTANT;
    this->coeff = val;
}


Expression::Expression(Complex val){
    this->init();
    this->type = CONSTANT;
    this->coeff = val;
}


Expression::Expression(std::string value, Complex coeff){
    this->validate_symbol(value);
    this->init();
    this->value = value;
    this->coeff = coeff;
}


Expression::Expression(Operator op){
    this->init();
    this->op = op;
    this->type = OPERATOR;
}


Expression::Expression(Function func, string value){
    this->validate_symbol(value);
    this->init();
    this->type = FUNCTION;
    this->func = func;
    this->exprs.push_back(Expression(value));
}


Expression::Expression(Function func, Expression expr){
    this->init();
    this->type = FUNCTION;
    this->func = func;
    this->exprs.push_back(expr);
}


void Expression::init(){
    this->value = "";
    this->coeff = 1.0;
    this->power = 1;
    this->type = SYMBOL;
    this->op = NO_OPERATOR;
    this->func = NO_FUNCTION;
    this->degree = -1;
}


size_t Expression::size(){
    return this->exprs.size();
}


std::vector<Expression, std::allocator<Expression>>::const_iterator Expression::begin(){
    return this->exprs.begin();
}


std::vector<Expression, std::allocator<Expression>>::const_iterator Expression::end(){
    return this->exprs.end();
}


// The expressions are put in the array in a sorted order
// Find the index for this new expression
int push_in_arr(vector<Expression>& exprs, Expression expr){
    int index = 0;
    for (auto exp: exprs){
        if (expr < exp)
            break;
        index++;
    }
    exprs.insert(exprs.begin()+index, expr);

    return index;
}


// return the index or array at which the expression must be kept
int Expression::push(Expression& expr, void(*func)(int, vector<Expression>&)=NULL){
    // this->exprs.push_back(exp);

    int index = push_in_arr(exprs, expr);

    if (func != NULL)
        func(index, this->exprs);
    return index;
}


// push all the expressions in the array in a sorted order
void Expression::push_all(Expression& expr, void(*func)(int, vector<Expression>&)=NULL){
    int index;
    for (auto exp: expr){
        index = this->push(exp, func);
    }
}


Type Expression::getType(){
    return this->type;
}


Operator Expression::getOperator(){
    return this->op;
}


string Expression::getValue(){
    return this->value;
}


Function Expression::getFunction(){
    return this->func;
}


Complex Expression::getCoeff(){
    return this->coeff;
}


// returns the degree of the expression
double Expression::getDegree(){
    this->degree = 0;
    if (this->type == CONSTANT);
    else if (this->exprs.size() <= 1)
        this->degree = this->power;
    else if (this->op == MULTIPLY)
        for (auto expr: *this)
            this->degree += expr.power;
    else if(this->op == DIVIDE || this->op == PLUS)
        return (*this)[0].getDegree();
    return this->degree;
}


// apply the function on the exprs vector
template <typename T>
Expression Expression::reduce(const T func, Expression init){
    Expression res = init;
    for (auto expr: *this){
        res = func(res, expr);
    }
    return res;
}


// TODO: replace Complex with Expression
Expression Expression::evaluate(map<string, Expression> values){
    if (this->power != 1){
        Expression expr = *this;
        expr.power = 1;
        auto val = expr.evaluate(values);
        return val^this->power;
    }
    if (this->type == CONSTANT)
        return pow(this->coeff, this->power);
    else if (this->type == SYMBOL){
        if (values.find(value) == values.end())
            return *this;
        else
            return Expression(this->coeff * values[this->value]);
    }
    else if (this->type == FUNCTION){
        Expression expr = this->exprs[0].evaluate(values);
        if (expr.type == CONSTANT){
            if (this->func == SIN)
                return sin(expr.coeff);
            else if (this->func == COS)
                return cos(expr.coeff);
            else if (this->func == TAN)
                return tan(expr.coeff);
            else if (this->func == COSEC)
                return 1/sin(expr.coeff);
            else if (this->func == SEC)
                return 1/cos(expr.coeff);
            else if (this->func == COT)
                return 1/tan(expr.coeff);
            else if (this->func == GIF)
                return floor(expr.coeff);
            else if (this->func == SIF)
                return ceil(expr.coeff);
            else if (this->func == ABS)
                return abs(expr.coeff);
            else
                throw BugException("Function not implemented");
        } else {
            return Expression(this->func, this->coeff * expr);
        }
    }
    else if (this->op == PLUS){
        return this->coeff * reduce([values](Expression& left, Expression& right){return left.evaluate(values) + right.evaluate(values);}, Expression(Complex(0)));
    }
    else if (this->op == MULTIPLY)
        return this->coeff * reduce([values](Expression& left, Expression& right){return left.evaluate(values) * right.evaluate(values);}, Expression(1));
    else if (this->op == DIVIDE)
        return this->coeff * this->exprs[0].evaluate(values) / this->exprs[1].evaluate(values);
    return Complex(0);
}

Expression Expression::differentiate(Expression exp){

    if (exp.type != SYMBOL)
        throw NotDifferentiableException("Differentiation variable must be a symbol");

    // const
    Expression result;

    if (this->type == CONSTANT){
        return 0;
    }
    else if (this->power !=1 ){
        result = *this;
        result.power--;
        Expression exp2 =  *this;
        exp2.power = 1;

        result = result *(result.power+1) * exp2.differentiate(exp);
    }
    else if (this->type == FUNCTION){
        if (this->func == GIF){
            throw NotDifferentiableException("GIF Function is not differentiable\n");
        }
        else if (this->func == SIF){
            throw NotDifferentiableException("SIF Function is not differentiable\n");
        }
        else if (this->func == ABS){
            throw NotDifferentiableException("Absolute Function is not differentiable\n");
        }
        else if (this->func == SIN){
            result = cos(this->exprs[0]) * this->exprs[0].differentiate(exp);
        }
        else if (this->func == COS){
            result = -sin(this->exprs[0]) * this->exprs[0].differentiate(exp);
        }
        else if (this->func == TAN){
            result =  ((sec(this->exprs[0])^2))  * this->exprs[0].differentiate(exp);
        }
        else if (this->func == COSEC){
            result =  -(cosec(this->exprs[0])*cot(this->exprs[0]))  * this->exprs[0].differentiate(exp);
        }
        else if (this->func == SEC){
            result =  (sec(this->exprs[0]) * tan(this->exprs[0]))  * this->exprs[0].differentiate(exp);
        }
        else if (this->func == COT){
            result =  -(cosec(this->exprs[0])^2)  * this->exprs[0].differentiate(exp);
        }
    }
    else if (this->type == OPERATOR){
        if (this->op == PLUS){

            result = 0;
            for (int i=0; i< this->exprs.size(); i++){
                result = result + this->exprs[i].differentiate(exp);
                
            }

        }
        else if (this->op == MULTIPLY){

            result = 0;
            for (int i=0; i<this->exprs.size(); i++){
                Expression temp = 1;
                for (int j=0; j<this->exprs.size(); j++){
                    if (i != j){
                        temp = temp * this->exprs[j];
                    }
                }
                result = result + temp * this->exprs[i].differentiate(exp);
            }
        }
        else if (this->op == DIVIDE){

            result = ((this->exprs[0].differentiate(exp) * this->exprs[1]) - (this->exprs[1].differentiate(exp) * this->exprs[0]))/ ((this->exprs[1]) ^ 2);
        }

    }
    else if (this->type == SYMBOL){
        if (this->value == exp.value){
            return this->coeff;
        }

        return 0;
    }

    
    return result* this->coeff;
}

Expression Expression::differentiate(string exp){
    return this->differentiate(Expression(exp));
}

Expression Expression::differentiate(Expression exp, int n){
    Expression expr = *this;

    for (int i=0; i<n; i++){
        expr = expr.differentiate(exp);
    }
    return expr;
}

Expression Expression::differentiate(string exp, int n){
    return this->differentiate(Expression(exp), n);
}

// override for cout to print the expression to output stream
ostream& operator<<(ostream& os, const Expression& expr){
    return os << ("" << expr);
}


// Get string representation of the expression
std::string operator<<(std::string str, const Expression& expr){
    std::string ret = "";
    std::string temp;
    // if coeff is 0 then don't print the expression
    if (expr.coeff == 0)
        return "0";

    // TODONE: check this functionality
    if (expr.type == FUNCTION){
        ret += expr.functions[expr.func] + ("(" << expr.exprs[0]) + ")";
    }
    // if it is a constant then print the coefficient
    else if (expr.type == CONSTANT){
        ret += without_trail_0(expr.coeff);
    }
    // if it consists of multiple parts then print everything one by one
    else if (expr.op != NO_OPERATOR){

        // // add a '(' if the operator is not multiplication operator
        // ret = (ret + (expr.op == MULTIPLY ? "" : "")) << expr.exprs.at(0);
        // for (int i=1; i<expr.exprs.size(); i++){
        //     temp = "" << expr.exprs.at(i);
        //     if (temp == "")
        //         continue;
        //     if (expr.op == PLUS && temp[0] == '-'){
        //         ret += temp;
        //     }
        //     else{
        //         ret = ret+expr.operators[expr.op] + temp;
        //     }
        // }
        // // and close with ')' if operator is not multiplication
        // ret += (expr.op == MULTIPLY ? "" : "");

        if (expr.op == DIVIDE){
            // for PLUS in numerator or denominator add parenthesis
            if (expr.exprs[0].op == PLUS){
                ret.push_back('(');
                ret = ret << expr.exprs[0];
                ret.push_back(')');
            } else {
                ret = ret << expr.exprs[0];
            }
            ret.push_back('/');
            if (expr.exprs[1].op == PLUS || expr.exprs[1].op == MULTIPLY){
                ret.push_back('(');
                ret = ret << expr.exprs[1];
                ret.push_back(')');
            } else {
                ret = ret << expr.exprs[1];
            }
        } else if (expr.op == MULTIPLY) {
            int n = expr.exprs.size();
            for (int i=0; i<n; i++){
                auto exp = expr.exprs[i];
                if (exp.op == NO_OPERATOR){
                    ret = ret << exp;
                } else { // this must be PLUS
                    if (exp.op != PLUS){
                        throw BugException("Operator inside MULTIPLY must be PLUS");
                    }
                    ret.push_back('(');
                    ret = ret << exp;
                    ret.push_back(')');
                }
                if (i != n-1){
                    ret.push_back('*');
                }
            }
        } else { // PLUS
            int n = expr.exprs.size();
            for (int i=0; i<n; i++){
                auto exp = expr.exprs[i];
                string tmp;
                tmp = "" << exp;
                if (tmp == "")
                    continue;
                if (i != 0 && tmp[0] != '-'){
                    ret.push_back('+');
                }
                ret += tmp;
            }
        }
    }
    else {
        ret += expr.value;
    }

    // add the coeffecient part
    if (expr.coeff!=1.0)
        if (expr.coeff == -1.0 && ret[0] != '-')
            ret = "-" + ret;
        else if(expr.type != CONSTANT)
            ret = without_trail_0(expr.coeff) + "*" + ret;

    // add the power part
    if (expr.power != 1){
        if (expr.op != NO_OPERATOR){
            ret = "(" + ret + ")";
        }
        ret = ret + "^" + without_trail_0(expr.power);
    }

    return str + ret;
}


// simplify the expression after addition
void after_push_plus(int index, vector<Expression>& exprs){
    // check if adjacent expressions are same.
    // if yes then merge them and add the coeffs
    if (exprs.size() <= 1){
        return;
    }
    if (index == 0){}
    else if (exprs[index] == exprs[index-1]){
        Expression expr;
        // size == 0: It is constant or a symbol
        if (exprs[index].size() == 0)
            if (exprs[index].type == CONSTANT)
                expr = {exprs[index].coeff+exprs[index-1].coeff};
            // else if (exprs[index].func != NO_FUNCTION){
            //     expr = {exprs[index].value, exprs[index].func};
            //     expr.coeff = exprs[index].coeff+exprs[index-1].coeff;
            // }
            else
                expr = {exprs[index].value, exprs[index].coeff+exprs[index-1].coeff};
        else{
            expr = {"", exprs[index].coeff+exprs[index-1].coeff};
            expr.push_all(exprs[index]);
        }
        exprs.erase(exprs.begin()+index);
        exprs.erase(exprs.begin()+index-1);
        exprs.insert(exprs.begin()+index-1, expr);
        return;
    }

    if (index == exprs.size()-1){}
    else if(exprs[index] == exprs[index+1]){
        Expression expr;
        if (exprs[index].size() == 0)
            if (exprs[index].type == CONSTANT)
                expr = {exprs[index].value+exprs[index+1].value};
            // else if (exprs[index].func != NO_FUNCTION){
            //     expr = {exprs[index].value, exprs[index].func};
            //     expr.coeff = exprs[index].coeff+exprs[index+1].coeff;
            // }
            else
                expr = {exprs[index].value, exprs[index].coeff+exprs[index+1].coeff};
        else{
            expr = {"", exprs[index].coeff+exprs[index+1].coeff};
            expr.push_all(exprs[index]);
        }
        // Expression expr = {exprs[index].getValue(), exprs[index].getCoeff()+exprs[index+1].getCoeff()};
        // expr.push_all(exprs[index]);
        exprs.erase(exprs.begin()+index);
        exprs.erase(exprs.begin()+index);
        exprs.insert(exprs.begin()+index, expr);
        return;
    }
}


// override for + operator
Expression Expression::operator+(Expression expr){
    Expression exp = {PLUS};

    // if this has + operator then push its exprs to new expr
    // and then check for duplicate expressions
    if (this->op == PLUS){
        exp.push_all(*this, after_push_plus);
    }
    else{ // if this's operator isn't + then push this expr and fix dups
        exp.push(*this, after_push_plus);
    }
    if (expr.op == PLUS){ // do same for `expr`
        exp.push_all(expr, after_push_plus);
    }
    else{
        exp.push(expr, after_push_plus);
    }

    exp = remove_zeroes(exp);

    // check for and fix singlet exprs
    return fix_singlet(exp);
}

Expression remove_zeroes(Expression exp){

    Expression n_exp = exp;
    n_exp.exprs.clear();

    for (int i=0; i< exp.exprs.size(); i++){
        if (exp.exprs[i].coeff != 0){
            n_exp.exprs.push_back(exp.exprs[i]);
        }
    }

    if (n_exp.exprs.size() == 0){
        n_exp.exprs.push_back(0);
    }
    return n_exp;
}

// Expression Expression::operator+(Complex value){
//     return *this + Expression(value);
// }


Expression operator+(Complex value, Expression expr){
    return expr + value;
}


Expression Expression::operator+=(Expression expr){
    *this = *this + expr;
    return *this;
}


// negate the expression
Expression Expression::operator-(){
    Expression exp;
    // if operator is PLUS then multiply the
    // coeffs of all the elements of exprs
    if (this->op == PLUS){
        exp = {PLUS};
        for (auto ep: *this){
            Expression expr = -ep;
            exp.push(expr);
        }
    }

    else{ // multiply the coeff of this expr with -1
        exp = *this;
        exp.coeff = -this->coeff;
    }

    return exp;
}


Expression Expression::operator-(Expression expr){
    Expression exp = *this + (-expr);

    return exp;
}


// Expression Expression::operator-(Complex val){
//     return *this + (-val);
// }


Expression operator-(Complex value, Expression expr){
    return -expr + value;
}


// this is run after a multiplication to find duplicates and
// add their powers
void after_push_mult(int index, vector<Expression>& exprs){
    for (int i=0; i<exprs.size(); i++){
        // compare this index's value with all others and
        // if they are equal then add their powers
        if (i != index){
            if (eq_without_pow(exprs[i], exprs[index], false)){
                Expression expr = exprs[index];
                expr.coeff = exprs[index].coeff * exprs[i].coeff;

                // if expr is not constant then only add the powers
                if (exprs[index].type != CONSTANT)
                    expr.power = exprs[index].power + exprs[i].power;
                exprs.erase(exprs.begin()+max(index, i));
                exprs.erase(exprs.begin()+min(index, i));
                push_in_arr(exprs, expr);
                return;
            }
        }
    }
}


Expression multiply(Expression expr1, Expression expr2, bool broadcast=false){
    Expression ret(MULTIPLY);
    // if both are constant then return a constant expr
    // with coeff = coeff1 * coeff2
    if (expr1.type == CONSTANT && expr2.type == CONSTANT){
        ret.type = CONSTANT;
        ret.coeff = expr1.coeff * expr2.coeff;
        ret.op = NO_OPERATOR;
    }
    // if this is constant and other is not then
    else if (expr1.type == CONSTANT && expr2.type != CONSTANT){
        // if operator is PLUS then multiply the constant to coeffs of all
        // the elements of the exprs
        if (expr2.op == PLUS){
            ret.op = PLUS;
            for (auto ep: expr2){
                Expression exi = ep * (expr1);
                ret.push(exi, after_push_plus);
            }
        }
        // else take the product of the coeffs
        else {
            ret = expr2;
            ret.coeff *= expr1.coeff;
        }
    }
    else if (expr1.type != CONSTANT && expr2.type == CONSTANT){
        ret = expr2 * (expr1);
    }
    // TODONE: if they are NO_OPS then they can be funcs too
    // if both are symbols then add the symbols to a new expr with op = MULT
    else if (expr1.op == NO_OPERATOR && expr2.op == NO_OPERATOR){
        Expression ex = expr1;
        ex.coeff = 1;
        ret.push(ex);
        ex = expr2;
        ex.coeff = 1;
        ret.push(ex, after_push_mult);
        ret.coeff = expr1.coeff * expr2.coeff;
    }
    // if expr2 has no operator and expr1 has an operator
    else if (expr1.op != NO_OPERATOR && expr2.op == NO_OPERATOR){
        // In case of PLUS multiply all the elements of exprs with expr2
        if (expr1.op == PLUS){
            if (broadcast){
                ret.op = PLUS;
                for (auto exp: expr1){
                    Expression exi = multiply(exp, expr2, true);
                    ret.push(exi, after_push_plus);
                }
            } else {
                ret.op = MULTIPLY;
                expr1.simplify();
                if (expr1 < expr2){
                    ret.exprs.push_back(expr1);
                    ret.exprs.push_back(expr2);
                } else {
                    ret.exprs.push_back(expr2);
                    ret.exprs.push_back(expr1);

                }
            }
        }
        // for MULTIPLY, push the expr2 to exprs and multiply the coeffs
        else if (expr1.op == MULTIPLY){
            ret.coeff = expr1.coeff * expr2.coeff;
            expr2.coeff = 1;
            ret.push_all(expr1, after_push_mult);
            ret.push(expr2, after_push_mult);
        }
        // TODONE: Cancel out commons
        else if (expr1.op == DIVIDE){
            ret.op = DIVIDE;
            Expression ex1 = expr1[0]*expr2;
            Expression ex2 = expr1[1];
            ret.push(ex1);
            ret.push(ex2);
            cancel_commons(ret.exprs[0], ret.exprs[1], ret, true);
        }
    }
    else if (expr1.op == NO_OPERATOR && expr2.op != NO_OPERATOR){
        // ret = expr2 * (expr1);
        ret = multiply(expr2, expr1, broadcast);
    }

    // Now both will have operators
    else if (expr1.op == MULTIPLY && expr2.op == MULTIPLY){
        ret.push_all(expr1, after_push_mult);
        ret.push_all(expr2, after_push_mult);
        ret.coeff = expr1.coeff * expr2.coeff;
    }
    // TODONE: change this for divide
    else if (expr1.op == MULTIPLY && expr2.op == PLUS){
        if (broadcast){
            // multiply all the elements of expr2.exprs with expr1
            ret.op = PLUS;
            for (auto ep: expr2){
                Expression ex = multiply(ex, expr1, true);
                ret.push(ex, after_push_plus);
            }
        } else {
            ret = expr1;
            Expression tmp = expr2;
            tmp.simplify();
            ret.push(tmp, after_push_mult);
        }
    }
    else if (expr1.op == PLUS && expr2.op == MULTIPLY){
        ret = expr2 * (expr1);
    }
    // TODONE: change this for divide
    else if ((expr1.op == MULTIPLY || expr1.op == PLUS) && expr2.op == DIVIDE){
        ret.op = DIVIDE;
        Expression ex = (expr1) * expr2[0];
        ret.coeff = expr2.coeff * ex.coeff;
        ret.push(ex);
        ex = expr2[1];
        ret.push(ex);
    }
    else if (expr1.op == DIVIDE && (expr2.op == MULTIPLY || expr2.op == PLUS)){
        ret = expr2 * (expr1);
    }
    // this can be merged with PLUS and MULTIPLY case
    // TODONE: change this for divide
    else if (expr1.op == PLUS && expr2.op == PLUS){
        if (broadcast){
            ret.op = PLUS;
            for (auto ep: expr1){
                for (auto ex: expr2){
                    Expression exi = multiply(ep, ex, true);
                    ret.push(exi, after_push_plus);
                }
            }
        } else {
            ret.op = MULTIPLY;
            Expression tmp = expr1;
            tmp.simplify();
            ret.push(tmp);
            tmp = expr2;
            tmp.simplify();
            ret.push(tmp, after_push_mult);
        }
    }
    // if both are fractions then multiply the numerators and denominators
    // TODONE: Cancel out commons
    else if (expr1.op == DIVIDE && expr2.op == DIVIDE){
        ret.op = DIVIDE;
        Expression ep = (expr1)[0] * expr2[0];
        ret.push(ep);
        ep = (expr1)[1] * expr2[1];
        ret.push(ep);
        cancel_commons(ret.exprs[0], ret.exprs[1], ret, true);
    }

    if (ret != Expression(MULTIPLY)){
        return fix_singlet(ret);
    }
    throw BugException("All cases should have been covered (1)");
}


void Expression::simplify(){
    if (this->func != NO_FUNCTION){
        this->exprs[0].simplify();
        return;
    } else if (this->op == NO_OPERATOR)
        return;
    else if (this->op == PLUS){
        vector<Expression> exprs = this->exprs;
        this->exprs.clear();
        for (auto exp: exprs){
            exp.simplify();
            if (exp.op == PLUS){
                this->push_all(exp, after_push_plus);
            } else {
                this->push(exp, after_push_plus);
            }
        }
    } else if (this->op == MULTIPLY){
        Expression res(1);
        for (auto exp: this->exprs){
            exp.simplify();
            res = multiply(res, exp, true);
        }
        *this = res;
    } else if (this->op == DIVIDE){
        this->exprs[0].simplify();
        this->exprs[1].simplify();
    } else {
        BugException("All cases should have been covered (2)");
    }
}


// overload for the multiplication operator
Expression Expression::operator*(Expression expr){
    return multiply(*this, expr);
}


// Expression Expression::operator*(Complex value){
//     return (*this) * Expression(value);
// }


Expression operator*(Complex value, Expression expr){
    return expr * Expression(value);
}


// removes common terms from `expr1` and `expr2`
// changes original if `change` = `true` and expr2 = 1
// Note: always pass the numerator before denominator
void cancel_commons(Expression& expr1, Expression& expr2, Expression& original, bool change=false){
    if (expr1.op == MULTIPLY){
        for (Expression &expr: expr1.exprs){
            cancel_commons(expr, expr2, original);
        }
    } else if (expr2.op == MULTIPLY){
        for (Expression &expr: expr2.exprs){
            cancel_commons(expr1, expr, original);
        }
    } else {
        if (eq_without_pow(expr1, expr2, false)){
            if (expr1.power == expr2.power) {
                expr1 = expr2 = Expression(1);
            } else if (expr1.power < expr2.power) {
                expr2.power -= expr1.power;
                expr1 = Expression(1);
            } else if (expr1.power > expr2.power) {
                expr1.power -= expr2.power;
                expr2 = Expression(1);
            }
        }
    }
    expr1 = fix_singlet(expr1);
    expr2 = fix_singlet(expr2);
    vector<Expression> exprs;
    if (expr1.op == MULTIPLY){
        for (auto &expr: expr1.exprs){
            if (expr != Expression(1)){
                exprs.push_back(expr);
            }
        }
        if (exprs.size() == 0){
            expr1 = Expression(1);
        } else {
            expr1.exprs = exprs;
            exprs.clear();
        }
    }
    if (expr2.op == MULTIPLY){
        for (auto &expr: expr2.exprs){
            if (expr != Expression(1)){
                exprs.push_back(expr);
            }
        }
        if (exprs.size() == 0){
            expr2 = Expression(1);
        } else {
            expr2.exprs = exprs;
        }
    }

    if (change && expr2 == Expression(1)) {
        original = expr1;
    }
}


Expression Expression::operator/(Expression expr){
    Expression ret(DIVIDE);
    if (this->op == DIVIDE){
        if (expr.op == DIVIDE) {
            ret = (this->exprs[0] * expr.exprs[1]) / (this->exprs[1] * expr.exprs[0]);
        } else {
            ret = this->exprs[0] / (this->exprs[1] * expr);
        }
    } else if (expr.op == DIVIDE) {
        ret = expr / *this;
    } else if (expr.type == CONSTANT) {
        ret = *this;
        ret.coeff /= expr.coeff;
    } else {
        Expression exp = *this;
        exp.coeff = 1;
        ret.exprs.push_back(exp);
        exp = expr;
        exp.coeff = 1;
        if (exp.op == PLUS){
            exp.simplify();
        }
        ret.exprs.push_back(exp);
        ret.coeff = this->coeff / expr.coeff;
    }

    if (ret.op == DIVIDE){
        cancel_commons(ret.exprs[0], ret.exprs[1], ret, true);
        cancel_commons(ret.exprs[0], ret.exprs[1], ret, true);
    }

    return ret;
}

Expression Expression::operator/(Complex c){

    return (*this/Expression(c));
}

Expression operator/(Complex c, Expression exp){

    return (exp / c);
}

Expression Expression::operator^(double d){

    Expression exp = 1, tmp = *this;

    if (this->type == CONSTANT)
        exp = pow(this->coeff, d);
    else if (this->type == SYMBOL || this->type == FUNCTION){
        exp = *this;
        exp.power *= d;
    } else {
        if (d != (int)d)
            fprintf(stderr, "Warning: power on expresssion in not int");
        int t = (int)d;
        while (t){

            if (t%2){
                exp = exp * tmp;
            }
            tmp = tmp * tmp;
            t /= 2;
        }
    }

    return exp;
}

Expression Expression::operator^=(double d){

    this->power *= d;
    return *this;
}

Expression Expression::operator()(map<string, Expression> vals){

    return this->evaluate(vals);
}


// check if the expressions are equal if power is not considered
bool eq_without_pow(Expression expr1, Expression expr2, bool check_coeff=false){

    if (check_coeff && expr1.coeff != expr2.coeff)
        return false;
    if (expr1.type == CONSTANT && expr2.type == CONSTANT)
        return true;
    if (expr1.size() != expr2.size() || expr1.op != expr2.op || 
            expr1.func != expr2.func)
        return false;
    
    if (expr1.size() == 0)
        return expr1.value == expr2.value;

    if (expr1.op != NO_OPERATOR){
        for (int i=0; i<expr1.size(); i++){
            if (!is_equal(expr1[i], expr2[i], true))
                return false;
        }
    }
    // for (int i=0; i<expr1.size(); i++){
    //     if (!is_equal(expr1[i], expr2[i], check_coeff))
    //         return false;
    // }
    return true;
}

bool is_equal(Expression expr1, Expression expr2, bool check_coeff=false){
    if (expr1.power != expr2.power || expr1.getDegree() != expr2.getDegree())
        return false;
    return eq_without_pow(expr1, expr2, check_coeff);
}

bool Expression::operator==(Expression expr){
    return is_equal(*this, expr);
}


bool Expression::operator==(Complex value){
    return *this == Expression(value);
}


bool operator==(Complex value, Expression expr){
    return expr == value;
}


bool Expression::operator!=(Expression expr){
    return ! (*this == expr);
}


bool Expression::operator!=(Complex val){
    return !(*this == Expression(val));
}


bool operator!=(Complex val, Expression expr){
    return !(expr == val);
}


// check if this < expr without considering functions
bool Expression::ltWithoutFunc(Expression& expr){
    if (is_equal(*this, expr, true))
        return false;
    // if degrees are equal then check the exprs vector
    if (this->getDegree() == expr.getDegree()){
        // if the sizes are 0 then comapare the values
        if (this->size() == 0 && expr.size() == 0)
            return this->value < expr.value;
        // if expr->size != 0 and this->size = 0 then
        // check the powers and then check the value
        else if (this->size() == 0)
            // if (this->power == expr.power)
            //     return this->value < expr.value;
            // else
            //     return this->power > expr.power;
            return true;
        // if this->size is not 0 then reverse
        else if(expr.size() == 0)
            // return !(expr < *this);
            return false;
        // now compare their sizes
        if (this->size() != expr.size()){
            return this->size() > expr.size();
        }
        // now go through all the elements of expr->exprs and this->exprs
        // and compare them
        if (this->op != expr.op)
            return false;
        for (int i=0; i<this->size(); i++){
            if (!is_equal((*this)[i], expr[i], true))
                return (*this)[i] < expr[i];
        }
        // by this point we should have come to a conclusion
        throw BugException("\033[01;31mError:\033[01;0m This line should not have been reached. A bug!");
    }
    return this->getDegree() > expr.getDegree();
}


bool Expression::operator<(Expression expr){
    if (*this == expr)
        return false;
    if (this->type == CONSTANT && expr.type == CONSTANT)
        return this->coeff < expr.coeff;
    if (this->type == CONSTANT && expr.type != CONSTANT)
        return false;
    if (this->type != CONSTANT && expr.type == CONSTANT)
        return true;
    if (this->func != NO_FUNCTION && expr.func == NO_FUNCTION)
        return false;
    if (this->func == NO_FUNCTION && expr.func != NO_FUNCTION)
        return true;
    if (this->func != NO_FUNCTION && expr.func != NO_FUNCTION)
        // compare the powers
        if (this->power != expr.power)
            return this->power > expr.power;
        // compare the functions
        else if (this->func != expr.func)
            return functions[this->func] < functions[expr.func];
        // if both power and function are equal then compare the argument
        // else
        //     for (int i=0; i<expr.size(); i++)
        //         if ((*this)[i] != expr[i])
        //             return (*this)[i] < expr[i];

    return this->ltWithoutFunc(expr);
}


bool Expression::operator<(Complex value){
    return *this < Expression(value);
}


bool operator<(Complex value, Expression expr){
    return !(expr<value && expr == value);
}


Expression Expression::operator[](int index){
    return this->exprs.at(index);
}


// converts a sum of fractions to a single fraction
void Expression::convert_sum_of_divs_to_single_div(){
    if (op == PLUS){
        op = DIVIDE;
        vector<Expression> denominators;
        for (auto ex: exprs){
            if (ex.op == DIVIDE){
                denominators.push_back(ex.exprs[1]);
            }
        }

        Expression numerator;

    }
}


Expression sin(Expression expr){
    if (expr.getType() == CONSTANT)
        return sin(expr.getCoeff());
    Expression exp = {SIN, expr};
    return exp;
}

Expression cos(Expression expr){
    if (expr.getType() == CONSTANT)
        return cos(expr.getCoeff());
    Expression exp = {COS, expr};
    return exp;
}

Expression tan(Expression expr){
    if (expr.getType() == CONSTANT)
        return tan(expr.getCoeff());
    Expression exp = {TAN, expr};
    return exp;
}

Expression cosec(Expression expr){
    if (expr.getType() == CONSTANT)
        return 1/sin(expr.getCoeff());
    Expression exp = {COSEC, expr};
    return exp;
}

Expression sec(Expression expr){
    if (expr.getType() == CONSTANT)
        return 1/cos(expr.getCoeff());
    Expression exp = {SEC, expr};
    return exp;
}

Expression cot(Expression expr){
    if (expr.getType() == CONSTANT)
        return 1/tan(expr.getCoeff());
    Expression exp = {COT, expr};
    return exp;
}


Expression floor(Expression expr){
    if (expr.getType() == CONSTANT)
        return floor(expr.getCoeff());
    Expression exp = {GIF, expr};
    return exp;
}


Expression ceil(Expression expr){
    if (expr.getType() == CONSTANT)
        return ceil(expr.getCoeff());
    Expression exp = {SIF, expr};
    return exp;
}


Expression abs(Expression expr){
    if (expr.getType() == CONSTANT)
        return abs(expr.getCoeff());
    Expression exp = {ABS, expr};
    return exp;
}

Expression sum(vector<Expression> exprs){
    Expression expr = 0;

    for (auto ex: exprs){
        expr = expr + ex;
    }
    return expr;
}

Complex::Complex(complex<double> c){

    this->real = c.real();
    this->imag = c.imag();
}
Complex::Complex(){

    this->real = 0.0;
    this->imag = 0.0;
}

Complex::Complex(double d){

    this->real = d;
    this->imag = 0.0;
}

Complex::Complex(double d1, double d2 ){

    this->real = d1;
    this->imag = d2;
}

double Complex::getReal(){

    return this->real;
}

double Complex::getImag(){

    return this->imag;
}

Complex Complex::operator+(Complex c){

    return Complex(c.real+real, c.imag + imag);
}

Complex Complex::operator+(double d){
    return Complex(d+this->real, this->imag);
}

Complex operator+(double d, Complex c){

    return c + d;
}

Complex Complex::operator+=(Complex c){

    this->real = this->real + c.real;
    this->imag = this->imag + c.imag;

    return *this;
}

Complex Complex::operator+=(double d){

    this->real = this->real + d;
    
    return *this;
}

Complex Complex::operator-(){

    return Complex(-real,-imag);
}

Complex Complex::operator-(Complex c){

    return Complex(real- c.real, imag - c.imag);
}

Complex Complex::operator-(double d){

    return Complex(real-d,imag);
}

Complex operator-(double d, Complex c){

    return (-c) + d;
}

Complex Complex::operator-=(Complex c){

    this->real -= c.real;
    this->imag -= c.imag;

    return *this;
}

Complex Complex::operator-=(double d){

    this->real -= d;
    return *this;
}

Complex Complex::operator*(Complex c){

    return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

Complex Complex::operator*(double d){

    return Complex(real * d, imag * d);
}

Complex operator*(double d,Complex c){

    return c*d;
}

Complex Complex::operator*=(Complex c){

    this->real = this->real * c.real - this->imag * c.imag;
    this->imag = this->real * c.imag + this->imag * c.real;
    // *this = *this*c (will this work ?)

    return *this;
}

Complex Complex::operator*=(double d){

    this->real = this->real * d;
    this->imag = this->imag * d;
    // *this = *this*d

    return *this;

}

double Complex::normsq(){

    return real*real + imag*imag;
}

Complex Complex::conjugate(){

    return Complex(real,-imag);
}

Complex Complex::operator/(Complex c){

    return Complex((real*c.real + imag*c.imag)/c.normsq(), (imag*c.real - real*c.imag)/c.normsq());
}

Complex Complex::operator/(double d){

    return Complex(real/d,imag/d);
}

Complex operator/(double d, Complex c){

    return c.conjugate()*d / c.normsq();
}

Complex Complex::operator/=(Complex c){

    this->real = (real*c.real + imag*c.imag)/c.normsq();
    this->imag = (imag*c.real - real*c.imag)/c.normsq();

    return *this;

}

Complex Complex::operator/=(double d){

    this->real = this->real/d;
    this->imag = this->imag/d;

    return *this;
}

Complex Complex::operator^(double d){

    return pow(complex(real,imag),d);
}

Complex Complex::operator^=(double d){

    Complex c = pow(complex(real,imag),d);

    this->real = this->real + c.getReal();
    this->imag = this->imag + c.getImag();

    return *this; 
}

bool Complex::operator==(Complex c){
    return (real == c.real && imag == c.imag);
}

bool Complex::operator==(double d){
    return (real == d && imag == 0);
}

bool operator==(double d,Complex c){
    return c==d;

}

bool Complex::operator!=(Complex c){
    return !(*this == c);
}

bool Complex::operator!=(double d){
    return !(*this == d);
}

bool operator!=(double d, Complex c){
    return (c != d);
}

bool Complex::operator<(Complex c){
    return (real < c.real || (real == c.real && imag < c.imag));
}   

bool Complex::operator<(double d){
    return (real < d || (real == d && imag < 0));
}

bool operator<(double d, Complex c){
    return (c<d);
}

bool Complex::operator>(Complex c){
    return (real > c.real || (real == c.real && imag > c.imag));

}

bool Complex::operator>(double d){
    return (real > d || (real == d && imag > 0));

}

bool operator>(double d, Complex c){
    return (c>d);

}

bool Complex::operator<=(Complex c){
    return !(*this > c);
}

bool Complex::operator<=(double d){
    return !(*this > d);
}

bool operator<=(double d, Complex c){
    return !(c>d);
}

bool Complex::operator>=(Complex c){
    return !(*this < c);
}

bool Complex::operator>=(double d){
    return !(*this < d);
}

bool operator>=(double d, Complex c){
    return !(c<d);
}

ostream& operator<<(ostream& os, const Complex& c){
    return os << ("" << c);
}

std::string operator<<(std::string s, const Complex& c){
    return s + without_trail_0(c);
}

Complex sin(Complex c){
    return sin(complex(c.getReal(),c.getImag()));

}

Complex cos(Complex c){
    return cos(complex(c.getReal(),c.getImag()));
}

Complex tan(Complex c){
    return tan(complex(c.getReal(),c.getImag()));
}

Complex cosec(Complex c){
    return 1.0/sin(c);
}

Complex sec(Complex c){
    return 1.0/cos(c);
}

Complex cot(Complex c){
    return 1.0/tan(c);
}

Complex floor(Complex c){
    return Complex(floor(c.getReal()),floor(c.getImag()));
}

Complex ceil(Complex c){
    return Complex(ceil(c.getReal()),ceil(c.getImag()));
}

Complex abs(Complex c){
    return Complex(abs(c.getReal()),abs(c.getImag()));
}

Complex pow(Complex c1, Complex c2){
    return pow(complex<double>(c1.getReal(), c1.getImag()), complex<double>(c2.getReal(), c2.getImag()));
}

int factorial(int n){
    if (n == 0)
        return 1;
    return n*factorial(n-1);
}
