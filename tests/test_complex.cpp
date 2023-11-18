#include "expr_base.hpp"


using namespace std;


int main(){
    Complex x(1, 2);
    Complex y(3, 4);
    Complex z(5, 6);
    
    Expression t = {"x"};
    cout << t.differentiate("x")  << endl;

    return 0;
}

