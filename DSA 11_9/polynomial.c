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

