#include <stdio.h>

int fraction(double a, int *b, double *c){
    *b = (int)a;
    *c = a - *b;
}

int main(){
    double n;
    int integer;
    double frac;
    printf("Enter double parameter: ");
    scanf("%lf", &n);
    fraction(n, &integer, &frac);
    printf("Integer: %d\n", integer);
    printf("Fraction: %lf\n", frac);
}