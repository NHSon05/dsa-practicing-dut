#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char CCCD[20];
    char name[50];
    char stockCode[20];
    int shares;
};

struct Node {
    struct Person data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node* List;
typedef struct Node* Position;

// Tạo danh sách rỗng có header
List create() {
    List header = (struct Node*) malloc(sizeof(struct Node));
    header->next = NULL;
    header->prev = NULL;
    return header;
}

// Thêm một người vào sau header
void insert(List pL, struct Person p) {
    Position newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = p;
    newNode->next = pL->next;
    newNode->prev = pL;
    if (pL->next != NULL) pL->next->prev = newNode;
    pL->next = newNode;
}

// In toàn bộ danh sách
void show(List pL) {
    Position cur = pL->next;
    while (cur != NULL) {
        printf("CCCD: %s | Name: %s | Stock: %s | Shares: %d\n",
               cur->data.CCCD, cur->data.name, cur->data.stockCode, cur->data.shares);
        cur = cur->next;
    }
}

// Liệt kê theo mã chứng khoán
void findByStock(List pL, char code[]) {
    Position cur = pL->next;
    while (cur != NULL) {
        if (strcmp(cur->data.stockCode, code) == 0) {
            printf("CCCD: %s | Name: %s | Shares: %d\n",
                   cur->data.CCCD, cur->data.name, cur->data.shares);
        }
        cur = cur->next;
    }
}

// Người có nhiều cổ phiếu nhất
void findMaxShares(List pL) {
    Position cur = pL->next;
    Position maxNode = NULL;
    int maxShares = -1;
    while (cur != NULL) {
        if (cur->data.shares > maxShares) {
            maxShares = cur->data.shares;
            maxNode = cur;
        }
        cur = cur->next;
    }
    if (maxNode != NULL) {
        printf("Người nhiều cổ phiếu nhất: %s (%d)\n", 
                maxNode->data.name, maxNode->data.shares);
    }
}

// Xóa theo CCCD
void deleteByCCCD(List pL, char cccd[]) {
    Position cur = pL->next;
    while (cur != NULL) {
        if (strcmp(cur->data.CCCD, cccd) == 0) {
            if (cur->prev != NULL) cur->prev->next = cur->next;
            if (cur->next != NULL) cur->next->prev = cur->prev;
            free(cur);
            printf("Đã xóa người có CCCD %s\n", cccd);
            return;
        }
        cur = cur->next;
    }
    printf("Không tìm thấy CCCD %s\n", cccd);
}

int main() {
    List pL = create();

    struct Person p1 = {"001", "Nguuyen Thai Phu", "VCB", 1000};
    struct Person p2 = {"002", "Pham Tien", "VCB", 2000};
    struct Person p3 = {"003", "Cuong", "FPT", 1500};
    insert(pL, p1);
    insert(pL, p2);
    insert(pL, p3);

    printf("Danh sách:\n");
    show(pL);

    printf("\nTìm theo mã VCB:\n");
    findByStock(pL, "VCB");

    printf("\nNgười nhiều cổ phiếu nhất:\n");
    findMaxShares(pL);

    printf("\nXóa CCCD 002:\n");
    deleteByCCCD(pL, "002");
    show(pL);

    return 0;
}