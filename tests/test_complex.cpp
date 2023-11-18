#include "expr_base.hpp"


using namespace std;


int main(){
    Complex x(1, 2);
    Complex y(3, 4);
    Complex z(5, 6);

    cout << ((sin(z)^2) + (cos(z)^2)) << "\n" << z/3  << "\n"<<  tan(z) << endl;

    return 0;
}

