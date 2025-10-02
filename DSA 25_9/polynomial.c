#include <stdio.h>
#include <stdlib.h>

//  Tạo một cái struct
struct Polynomial_Info{
    int exp; // khai báo hàm mũ
    int *coeff; // con trỏ tới 1 mảng số nguyên và gán cho nó là giá trị
};

// Định nghĩa cho kiểu dữ liệu
typedef struct Polynomial_Info *Polynomial;

// Tạo một đa thức mới
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
    int first = 1;
    for (int i = P->exp; i >= 0; i--){
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

Polynomial add_polynomial(Polynomial A, Polynomial B){
    // Tạo mới số mũ và hệ so cho đa thức C
    int max_exp = A -> exp > B -> exp ? A->exp : B->exp;
    int *coeff = malloc(sizeof(int) * (max_exp + 1));

    // Khởi tạo mảng coeff về 0
    for (int i = 0; i <= max_exp; i++) {
        coeff[i] = 0;
    }
    // Tạo mới một Polynomial C gồm hệ số max_exp và coeff
    Polynomial C = create(max_exp, coeff);
    for (int i = 0; i<=max_exp; i++){
        if (i > A->exp)
            C->coeff[i] = B->coeff[i];
        else if (i>B->exp)
            C->coeff[i] = A -> coeff[i];
        else    C->coeff[i] = A->coeff[i] + B->coeff[i];
    }
    free(coeff);
    return C;
}

Polynomial multi_polynomial(Polynomial A, Polynomial B){
    int max_exp = A->exp + B->exp;  // New maximum exponent is sum of exponents
    // Để lấy đa thức kết quả C có bậc cao nhất
    int *coeff = malloc(sizeof(int) * (max_exp + 1));

    // Initialize all coefficients to 0
    for (int i = 0; i <= max_exp; i++) {
        coeff[i] = 0;
    }

    // Multiply each term of A with each term of B
    for (int i = 0; i <= A->exp; i++) {
        for (int j = 0; j <= B->exp; j++) {
            // When multiplying x^i with x^j, we get x^(i+j)
            coeff[i + j] += A->coeff[i] * B->coeff[j];
        }
    }

    Polynomial C = create(max_exp, coeff);
    free(coeff);
    return C;
}

int main(){
    int coeff_1[] = {10,4,0,7};
    Polynomial A = create(3, coeff_1);
    printf("A(x): ");
    show(A);

    int coeff_2[] = {11,1,0,1};
    Polynomial B = create(3, coeff_2);
    printf("B(x): ");
    show(B);

    printf("Sum of polynomials: ");
    show(add_polynomial(A,B));
    
    printf("Product of polynomials: ");
    show(multi_polynomial(A,B));

    return 0;
}
