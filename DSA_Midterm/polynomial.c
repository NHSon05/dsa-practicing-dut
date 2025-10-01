#include <stdio.h>
#include <stdlib.h>


// struct Polynomial{
//     int exp;
    
// }
typedef struct Polynomial {
    int exp;   
    int *coeff; 
} *Polynomial;

Polynomial createPoly(int exp, int coeff[]) {
    Polynomial P = malloc(sizeof(struct Polynomial));
    P->exp = exp;
    P->coeff = malloc(sizeof(int) * (exp + 1));
    for (int i = 0; i <= exp; i++) P->coeff[i] = coeff[i];
    return P;
}

void showPoly(Polynomial P) {
    int first = 1;
    for (int i = P->exp; i >= 0; i--) {
        if (P->coeff[i] != 0) {
            if (!first) printf(" + ");
            if (i == 0) printf("%d", P->coeff[i]);
            else if (i == 1) printf("%dx", P->coeff[i]);
            else printf("%dx^%d", P->coeff[i], i);
            first = 0;
        }
    }
    if (first) printf("0");
    printf("\n");
}

Polynomial addPoly(Polynomial A, Polynomial B) {
    int maxExp = (A->exp > B->exp) ? A->exp : B->exp;
    int *coeff = calloc(maxExp + 1, sizeof(int));
    for (int i = 0; i <= A->exp; i++) coeff[i] += A->coeff[i];
    for (int i = 0; i <= B->exp; i++) coeff[i] += B->coeff[i];
    return createPoly(maxExp, coeff);
}

Polynomial mulPoly(Polynomial A, Polynomial B) {
    int maxExp = A->exp + B->exp;
    int *coeff = calloc(maxExp + 1, sizeof(int));
    for (int i = 0; i <= A->exp; i++)
        for (int j = 0; j <= B->exp; j++)
            coeff[i+j] += A->coeff[i] * B->coeff[j];
    return createPoly(maxExp, coeff);
}

int main() {
    int coeffA[] = {7, 0, 4, 10}; 
    Polynomial A = createPoly(3, coeffA);

    int coeffB[] = {-4, 4}; 
    Polynomial B = createPoly(1, coeffB);

    printf("A(x) = "); showPoly(A);
    printf("B(x) = "); showPoly(B);

    Polynomial C = addPoly(A, B);
    printf("A + B = "); showPoly(C);

    Polynomial D = mulPoly(A, B);
    printf("A * B = "); showPoly(D);

    return 0;
}
