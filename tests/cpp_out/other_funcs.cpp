import "funcs.lg";

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

func void print_curve(curve c){

}


func int main(){
    complex <int, int> c = {1, 2};
    curve y (x, a, b) = $a * sin($x) + $b * cos($x) ^ 2 + $a * $b;
    curve w (x) = $x^4 + 3*$x^2 - 2*$x;

    curve z(y) = input_poly(5) / w($y); 

    curve z2(y) = z * $y; 

    curve y1 = D[y, $x];

    z2 = D[z2, $x];
    curve z3 = D[y*z2, $x];

    print_curve(z3);

    return 0;
}
