#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------- PHẦN KHAI BÁO -----------------------
struct Person {
    char CCCD[20];      // Khai báo biến CCCD chứa 20 kí tự
    char name[50];      // Khai báo tên với 50 ký tự
    char stockCode[20]; // Khai báo mã chứng khoáng với 20 kí tự
    int shares;         // Khai báo số lượng cổ phiếu
};

struct Node {
    struct Person data; // Dữ liệu người
    struct Node* prev;  // Con trỏ trỏ tới nút trước
    struct Node* next;  // Con trỏ trỏ tới nút sau
};

typedef struct Node* List;  //  Con trỏ trỏ đến một struct Node: typedef cho phép đặt tên mới cho 1 kiểu dữ liệu
typedef struct Node* Position;  // Tương tự trỏ tới địa chỉ
// ------------------------------------------------------------

// Tạo danh sách rỗng có header
List create() {
    Position header = malloc(sizeof(struct Node)); // cấp phat bộ nhớ với khối lượng đủ lớn để chứa một cấu trúc node
    // List header = (struct Node*) malloc(sizeof(struct Node)); // Cấp bộ nhớ cho kiểu dữ liệu này
    header->next = NULL;
    header->prev = NULL;
    return header;
}

// Thêm một người vào sau header
// Chèn node mới chứa dữ liệu Person p sau node pL
// void insert(List pL, struct Person p) {
//     // Tạo ra một node rỗng mới
//     Position newNode = (struct Node*) malloc(sizeof(struct Node));
//     // gán dữ liệu p cho node mới
//     newNode->data = p;
//     // Cho newNode này thành pL
//     newNode->next = pL->next;
//     // Cho node mới này trả về ngược lại node pL
//     newNode->prev = pL;
//     if (pL->next != NULL) pL->next->prev = newNode;
//     pL->next = newNode;
// }

void insert(List pL, struct Person e, Position p){
    // Cấp phát bộ nhớ
    Position newNode = (struct Node*) malloc(sizeof(struct Node));
    // Gán thông tin người cho newNode
    newNode->data = e;
    // Trường hợp p bằng NULL => Gán cho giá trị tiếp theo của p
    if (p == NULL)
        p = pL;
    // cho node mới trỏ tới node đứng sau p
    newNode->next = p -> next;
    // cho node mới trỏ ngược lại p
    newNode->prev = p; // -> Node mới được chèn ngay sau p
    p->next = newNode;  // cho p trỏ tới newNode 
    //  Liên kết xuôi hoàn tất p -> newNode -> ...
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
    // nếu sau newNode còn node thì node đó phải cập nhật để tro về newNode
    // Tính liên kết dược đảm bảo
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
    insert(pL, p1, NULL);
    insert(pL, p2, NULL);
    insert(pL, p3, NULL);

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