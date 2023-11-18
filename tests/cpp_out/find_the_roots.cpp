

func curve abs(curve x){

}

func void print (string s, real x){

}

func int main(){
    int n = 10;
    curve g(x) = $x^2 + 1; 
    curve f(x);

    for i in 0..n {
        f += g(i) * $x^i;
    }

    
    real start = 0.0; 
    real epsilon = 0.0001;

    until ( abs(f(start)) < epsilon ) repeat
    {
        g = D[f, $x];
        start = start - f(start)/g(start);
    }

    print("One of the roots of the equation is ", start);

    return 0;
}
