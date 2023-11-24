#include "expr_base.hpp"
#include <assert.h>


using namespace std;


int main(){
    Expression x = {"x"};
    Expression y = {"y"};
    Expression z = {"z"};
    Expression s(SIN, "x");
    Expression exp, f;
    exp = z - y + x;

    // test1: Normal representation
    // cout << x << endl;
    // assert("" << x == "x");

    // cout << 1 - x << "\n";

    // // test2: Additions and substractions
    // cout << x+x*s << endl;
    // assert(""<<(x+x*s) == "x*sin(x)+x");
    // cout << x+y+z << endl;
    // assert(""<<x+y+z == "x+y+z");
    // cout << 8 + x + 6 - 1.0/3<< endl;
    // assert("" << (8+x+6-1.0/3) == "x+13.666667");
    // cout << x - 6 << endl;
    // assert("" << (x-6) == "x-6");
    // cout << -x << endl;
    // assert("" << -x == "-x");
    // cout << y-x << endl;
    // assert("" << (y-x) == "-x+y");
    // exp = y+z;
    // cout << (x-exp+s*x)*s << endl;
    // assert("" << (x-exp) == "x-y-z");
    // cout << -(x+y+z) << endl;
    // assert("" << -(x+y+z) == "-x-y-z");
    // cout << x+(y+z) << endl;
    // assert("" << (x+(y+z)) == "x+y+z");
    // cout << (x+y)+z << endl;
    // assert("" << ((x+y)+z) == "x+y+z");
    // cout << (x==x) << endl;
    // assert((x==x) == true);
    // cout << ((x+y) == (x+y)) << endl;
    // assert(((x+y) == (x+y)) == true);
    // cout << ((x+z) == (x+y)) << endl;
    // assert(((x+z) == (x+y)) == false);
    // cout << ((x+z)+y == (x+y)+z) << endl;
    // assert(((x+z)+y == (x+y)+z) == true);
    // cout << x+x+z-z-x+y+y<< endl;
    // assert("" << (x+x+z-z-x+y+y) == "x+2*y");
    // cout << x.getDegree() << endl;
    // assert(x.getDegree() == 1);

    // // test3: Multiplications
    // cout << x*2.0 << endl;
    // assert("" << (x*2.0) == "2*x");
    // cout << x*x << endl;
    // assert("" << x*x == "x^2");
    // cout << 2*x*y*2 << endl;
    // assert("" << (2*x*y*2) == "4*x*y");
    // cout << 2*(x+y) << endl;
    // assert("" << 2*(x+y) == "2*x+2*y");
    // cout << x*(x+y) << endl;
    // assert("" << (x*(x+y)) == "x*(x+y)");
    // cout << x*y + z + x<< endl;
    // assert("" << (x*y + z + x) == "x*y+x+z");
    // cout << (x*y + z + x).getDegree() << endl;
    // assert((x*y + z + x).getDegree() == 2);
    // cout << x*y*x-5*7*x + z*y << endl;
    // assert("" << (x*y*x-5*7*x + z*y) == "x^2*y+y*z-35*x");
    // cout << (x+y)*(x-y) << endl;
    // assert("" << (x+y)*(x-y) == "(x+y)*(x-y)");
    // cout << x*x + x*y << endl;
    // assert("" << (x*x + x*y) == "x^2+x*y");
    // cout << (y*y < x*x) << endl;
    // assert((y*y<x*x) == false);
    // cout << (x*y < x*x) << endl;
    // assert((x*y < x*x) == false);
    // cout << (x*x < x*y) << endl;
    // assert((x*x < x*y) == true);
    // cout << (x*x < x*x) << endl;
    // assert((x*x < x*x) == false);
    // cout << (x*x).getDegree() << endl;
    // assert((x*x).getDegree() == 2);
    // cout << (x*x*x*z*x*x)*(y*x*y*z) << endl;
    // assert("" << (x*x*x*z*x*x)*(y*x*y*z) == "x^6*y^2*z^2");
    // cout << (2*x*x + 4*y)*(-x*6+z*7) << endl;
    // assert("" << (2*x*x + 4*y)*(-x*6+z*7) == "(2*x^2+4*y)*(-6*x+7*z)");
    // cout << ((x*(x*x+y)+y) * (x*(x+y)+y)) << "\n";
    // assert("" << ((x*(x*x+y)+y) * (x*(x+y)+y)) == "(x^3+x*y+y)*(x^2+x*y+y)");
    // exp = x*(x+y)+y;
    // exp.simplify();
    // cout << exp << "\n";
    // assert("" << exp == "x^2+x*y+y");


    // // Divisions
    // cout << x/x << "\n";
    // cout << x / y * y << "\n";
    // cout << x / y * y / y << "\n";

    // // Evaluations
    // cout << ((x+y*x).evaluate({{"x", 1}, {"y", 2}, {"z", 3}})/(x-z+x*(x+y)).evaluate({{"x", 1}, {"y", 2}, {"z", 3}})) << "\n";
    // cout << (2*x).evaluate({{"x", 1}, {"y", 2}, {"z", 3}}) << "\n";
    // cout << (x+y).evaluate({{"x", 1}, {"y", 2}}).getCoeff() << "\n";

    // // Differentiation
    // cout << (x*x).differentiate(x) << "\n";
    // cout << (x^7).differentiate(x) << "\n";
    // cout << (x+1).differentiate(x) << "\n";
    // cout << (x/(x+1)).differentiate("x") << "\n";
    // cout << (Expression(2+x)*Expression(2*x)) << "\n";
    // cout << (Expression(x+ tan(x)).differentiate("y"))<< "\n";
    // cout << (Expression(4*(x^3) * y * cos(x)))<< "\n";
    // cout << (y*cos(x)/(x^4)).differentiate(x) << "\n";

    // f = x*x + x + y;
    // cout << f({{"x", y}}) << "\n";

    // f = x*x + (y^3) - 1;
    // cout << f << "\n";

    // cout << without_trail_0(-1.0) << "\n";

    Expression c1 = Expression("x") * Expression("x") + (Expression("y") ^ 3) - 1;
    cout << c1 << "\n";
    cout << (c1^2) << "\n";
}
