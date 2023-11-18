func curve input_poly(int n){
    curve f(x);
    int i;
    for i in 0..n{
        f = f + $x^i;
    }
    return f;
}

func void print_poly(curve f){
    
}

func curve sin(curve x){
    
}

func curve cos(curve x){
    
}

func void print(string s){

}

func int main(){
    curve f(x,y), g(x);
    f = input_poly(5);
    g = input_poly(7);

    curve h(x);
    h = D[f * g, $x];   

    D[h, $x];

    f = sin($x) * cos($x) + $x * sin($x) * $y;
    g = D[f($x), $x];          

    if (g != cos($x) * cos($x) - sin($x) * sin($x) + sin($x) + $x * cos($x)){
        print("Error in differentiation\n");
    }
    else
        print("Differentiation is correct\n");

    print_poly(h);
}
