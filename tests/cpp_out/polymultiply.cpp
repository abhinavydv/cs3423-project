
Expression input_poly(int n){
    Expression f(x);
    int i;
    return f;
}



void print_poly(Expression f){
    }



Expression sin(Expression x){
    }



Expression cos(Expression x){
    }



int print(string s, Expression c){
    }









int a;

complex FFT(Expression f, int degree);


Expression InverseFFT(Expression y, int degree);


Expression to_curve(complex y);


int main(){
    Expression f(x), g(x);
    f = input_poly(10);
    g = input_poly(9);
    complex<real, real> y_f, y_g;
    y_f = FFT(f, 10);
    y_g = FFT(g, 10);
    complex y;
    y = y_f * y_g;
    Expression c(k) = InverseFFT(to_curve(y), 11);
    print("Curve is ", c(Expression("t")));
    return 0;
}



complex to_complex(Expression x){
    }



complex FFT(Expression f, int degree){
    int e, k, _i_, pi, x;
    Expression zeroes(k) = e ^ 2 * k * _i_ * pi / degree + 1;
    Expression y_poly(x) = f(zeroes(x));
    degree += 1;
    a.b();
    vector<complex> y = {degree};
    for (auto i=0; i<degree; i++) {
        y[i] = to_complex(y_poly(i));
    }
    return y;
}



Expression InverseFFT(Expression y, int degree){
    int e, k, _i_, pi, x, i;
    Expression zeroes(k) = e ^ -2 * k * _i_ * pi / degree + 1;
    Expression y_poly(x);
    for (auto k=0; k<degree; k++) {
        y_poly += y(i) * x ^ i;
    }
    vector<complex> y2 = {degree};
    for (auto k=0; k<degree; k++) {
        y2[i] = to_complex(y_poly(zeroes(i)));
    }
    Expression c(x);
    for (auto k=0; k<degree; k++) {
        c += y_poly(zeroes(i)) * x ^ i;
    }
    return c(x);
}



