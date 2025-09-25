#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct NodeInfo {
    int coeff;
    int exp;
    // con trỏ trong ctdl danh sách kiên kết. 
    // Next là một con trỏ đến nút tiếp theo trong danh sách
    struct NodeInfo *next;
};

typedef struct NodeInfo *Node;
// Tạo một alias cho kiểu dữl iệu con trỏ trỏ đến struct Node. Cụ thể
typedef struct NodeInfo *Polynomial;

Polynomial create(){
    Polynomial header = malloc(sizeof(struct NodeInfo));
    header->exp = INT_MAX;
    header->next = NULL;
    return header; 
}

void add(Polynomial pL, int coeff, int exp){
    Node P = pL;
    while (pL->next != NULL && pL->next->exp >= exp)
        pL = pL->next;
    if (pL->exp == exp)
        pL->coeff += coeff;
    else {
        Node newNode = malloc(sizeof(struct NodeInfo));
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = pL->next;
        pL->next = newNode;
    }
}

void Show(Polynomial pL){
    pL = pL->next;
    while (pL != NULL){
        if (pL->exp != 0)
            printf("%dx^%d ", pL->coeff, pL->exp);
        else  printf("%d", pL->coeff);
        pL = pL->next;
    }
}

Polynomial sum(Polynomial A, Polynomial B) {
    Polynomial S = create();
    A = A->next;
    while (A != NULL) {
        add(S, A->coeff, A->exp);
        A = A->next;
    }
    B = B->next;
    while (B != NULL) {
        add(S, B->coeff, B->exp);
        B = B->next;
    }
    return S;
}

int main(){
    int coeff_1[] = {10,4,0,7};
    Polynomial A = create();
    add(A,2,0);
    add(A,2,1);
    add(A,2,2);
    add(A,2,3);
    add(A,2,2);
    Show(A);
    printf("\n");
    Polynomial B = create();
    add(B,3,0);
    add(B,3,1);
    add(B,3,3);
    add(B,3,4);
    add(B,3,2);
    Show(B);
    printf("\n");
    Polynomial S = sum(A,B);
    Show(S);
    return 0;
}