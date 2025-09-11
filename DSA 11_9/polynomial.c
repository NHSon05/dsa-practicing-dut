#include <stdio.h>
#include <stdlib.h>


struct Polynomial_Info{
    int exp;
    int *coeff;
};

typedef struct Polynomial_Info *Polynomial;

Polynomial create(int exp, int coeff[]){
    Polynomial P = malloc(sizeof(struct Polynomial_Info));
    P->exp = exp;
    P->coeff = malloc(sizeof(int) * (exp + 1));
    for (int i = 0; i <= exp; i++)
        P->coeff[i] = coeff[i];
    return P;
}

void show(Polynomial P) {
    for (int i = 0; i<= P-> exp; i++)
        if (P->coeff[i] != 0)
            printf("%dx^%d ", P->coeff[i], i);
    printf("\n");
}

int main(){
    int coeff_1[] = {10,4,0,7};
    Polynomial A = create(3, coeff_1);
    show(A);
    return 0;
}

