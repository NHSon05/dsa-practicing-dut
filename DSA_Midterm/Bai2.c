#include <stdio.h>
#include <stdlib.h>

struct Polynomial_Info{
    int exp;
    int *coeff;
};

typedef struct Polynomial_Info *Polynomial;

// Khai báo ra 1 hàm
Polynomial create(int exp, int coeff[]){
    Polynomial P = malloc(sizeof(struct Polynomial_Info));
    P->exp = exp;
    P->coeff = malloc(sizeof(int) * (exp + 1));
    for (int i = 0; i<=exp; i++)
        P->coeff[i] = coeff[i];
    return P;
}

// In ra cái đa thức này
void show(Polynomial P){
    int first = 1;
    for (int i = P->exp; i>=0;i--){
        if (P->coeff[i] != 0){
            if (!first) printf("+");
            if (i == 0) printf("%d,", P->coeff[i]);
            else if ( i == 1) printf("%dx", P->coeff[i]);
            else printf("%dx^%d", P->coeff[i], i);
            first = 0;
        }
    }
    if (first) printf("0");
    printf("\n");
}

// Hàm tính tổng
Polynomial add(Polynomial A, Polynomial B){
    int max_exp = A->exp > B->exp ? A->exp : B -> exp;
    int *coeff = malloc(sizeof(int) * (max_exp + 1));
    for (int i = 0; i<=max_exp;i++){
        coeff[i] = 0;
    }
    Polynomial C = create(max_exp, coeff);
    for (int i = 0; i<=max_exp;i++){
        if (i > A->exp) C->coeff[i] = B->coeff[i];
        else if (i > B->exp) C->coeff[i] = A->coeff[i];
        else C->coeff[i] = A->coeff[i] + B->coeff[i];
    }
    free(coeff);
    return C;
}

// Hàm nhân
Polynomial multi(Polynomial A, Polynomial B){
    int max_exp = A->exp + B->exp;
    int *coeff = malloc(sizeof(int) * (max_exp+1));

    for (int i = 0;i<max_exp;i++){
        coeff[i] = 0;
    }
    for (int i=0;i<=A->exp;i++){
        for (int j=0; j<=B->exp;j++){
            coeff[i+j] += A->coeff[i] * B->coeff[j];
        }
    }
    Polynomial C = create(max_exp, coeff);
    free(coeff);
    return C;
}

int main(){
    int coeff_1[] = {10,4,0,7};
    Polynomial A = create(3,coeff_1);
    printf("A:");
    show(A);

    int coeff_2[] = {10,4,0,7};
    Polynomial B = create(3,coeff_2);
    printf("B:");
    show(B);

    show(add(A,B));
    show(multi(A,B));
    return 0;
}