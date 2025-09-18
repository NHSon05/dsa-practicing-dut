#include <stdio.h>
#include <stdlib.h>

//  Tạo một cái struct
struct Polynomial_Info{
    int exp; // khai báo hàm mũ
    int *coeff; // con trỏ tới 1 mảng số nguyên và gán cho nó là giá trị
};

typedef struct Polynomial_Info *Polynomial;

Polynomial create(int exp, int coeff[]){
    // Cấp phát bộ nhớ động
    Polynomial P = malloc(sizeof(struct Polynomial_Info));
    // Gán giá trị bậc cao nhất cho exp của P
    P->exp = exp;
    
    P->coeff = malloc(sizeof(int) * (exp + 1));
    for (int i = 0; i <= exp; i++)
        P->coeff[i] = coeff[i];
    return P;
}

void show(Polynomial P) {
    for (int i = P->exp; i >= 0; i--)
        if (P->coeff[i] != 0)
            printf("%dx^%d ", P->coeff[i], i);
    printf("\n");
}

Polynomial add_polynomial(Polynomial A, Polynomial B){
    int max_exp = A -> exp > B -> exp ? A->exp : B->exp;
    int *coeff = malloc(sizeof(int) * (max_exp + 1));

    for (int i = 0; i <= max_exp; i++) {
        coeff[i] = 0;
        // int a_coeff = (i <= A->exp) ? A->coeff[i] : 0;
        // int b_coeff = (i <= B->exp) ? B->coeff[i] : 0;
        // coeff[i] = a_coeff + b_coeff;
    }
    Polynomial C = create(max_exp, coeff);
    for (int j = 0; j<=max_exp; j++){
        if (j> A->exp)
            C->coeff[j] = B->coeff[j];
        else if (j>B->exp)
            C->coeff[j] = A -> coeff[j];
        else    C->coeff[j] = A->coeff[j] + B->coeff[j];
    }
    free(coeff);
    return C;

}

int main(){
    int coeff_1[] = {10,4,0,7};
    Polynomial A = create(3, coeff_1);

    int coeff_2[] = {11,1,0,1};
    Polynomial B = create(3, coeff_2);

    show(add_polynomial(A,B));

    show(A);
    return 0;
}

