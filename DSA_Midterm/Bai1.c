#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------- PHẦN KHAI BÁO -------------------
struct Person {
    char CCCD[10];      // Khai báo biến CCCD chứa tối đa 20 kí tự + 1 ký tự null
    char name[20];     // Khai báo biến name chứa tối đa 100 kí tự + 1 ký tự null
    char stockCode[20];
    int shares;
};

// Khai báo kiểu dữ liệu Node
struct Node {
    struct Person data;
    struct Node *next;
    struct Node *prev;
};

// Định dạng kiểu dữ liệu
typedef struct Node* List;
typedef struct Node* Position;

// Hàm tạo
List create(){
    Position header = malloc(sizeof(struct Node));
    header -> next = NULL;
    header -> prev = NULL;
    return header;
}

// Hàm chèn
void insert(List pL, struct Person e, Position p){
    Position newNode = malloc(sizeof(struct Node ));
    // Gán data vào newNode
    newNode->data = e;
    // Xét điểm bắt đầu
    if (p == NULL)
        p = pL;
    newNode->next = p->next;
    // Trỏ về lại
    newNode->prev = p;
    // Cho p trỏ tới newNode
    p->next = newNode;
    // Trỏ tới vị trí cuối cùng
    if (newNode->next != NULL ){
        newNode->next->prev = newNode;
    }
}

// Hàm in ra
void show(List pL){
    Position cur = pL -> next;
    while (cur != NULL){
        printf("CCCD: %s | Name: %s | Stock: %s | Shares: %d\n", cur->data.CCCD, cur->data.name, cur->data.stockCode, cur->data.shares);
        cur = cur -> next;
    }
}

// Hàm liệt kê thông tin người có mã chứng khoán
void findStock(List pL,char code[]){
    Position cur = pL -> next;
    while (cur != NULL) {
        if (strcmp(cur->data.stockCode, code) == 0){
            printf("Name: %s\n", cur->data.name);
        }
        cur = cur-> next;
    }
}
// Hàm tìm lớn nhất
void maxShares(List pL){
    Position cur = pL -> next;
    Position maxNode = NULL;
    int maxShares = -1;
    while (cur != NULL){
        if (cur->data.shares > maxShares){
            maxShares = cur->data.shares;
            maxNode = cur;
        }
        cur = cur->next;
    }
    if (maxNode != NULL)
        printf("Người có nhiều cổ phiếu nhất: %s\n", maxNode->data.name);
}
void delete(List pL, char cccd[]){
    Position cur = pL -> next;
    while (cur != NULL){
        if (strcmp(cur->data.CCCD, cccd) == 0){
            if (cur -> prev != NULL) cur->prev->next = cur -> next;
            if (cur -> next != NULL) cur->next->prev = cur -> prev;
            free(cur);
            printf("Đã xoá người có CCCD: %s", cccd);
            return;
        }
        cur = cur->next;
    } 
    printf("Không tìm được CCCD: %s", cccd);
}

int main(){
    List pL = create();
    struct Person p1 = {"001", "Nguyen Son", "VCB", 1000};
    struct Person p2 = {"002", "Nguyen An", "VCL", 200};
    struct Person p3 = {"003", "Nguyen Tien", "VCC", 3000};
    struct Person p4 = {"004", "Nguyen Phu", "VCB", 4000};
    insert(pL, p1, NULL);
    insert(pL, p2, NULL);
    insert(pL, p3, NULL);
    insert(pL, p4, NULL);

    printf("----------------Show list---------------- \n");
    show(pL);
    printf("----------------Find StockCode---------------- \n");
    findStock(pL, "VCB");
    printf("----------------Most Shares---------------- \n");
    maxShares(pL);
    printf("----------------Delete---------------- \n");
    delete(pL, "002");
    printf("\n");
    show(pL);

    return 0;
}