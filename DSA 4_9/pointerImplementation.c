#include <stdio.h>
#include <stdlib.h>

// CTDL dùng để lưu thông tin của mỗi phần tủ, 
struct ElementType {
    int ID;             // Gồm số nguyên ID
    char *name;         // con trỏ chuỗi name
};

// Thành phần cốt lõi của danh sách
struct Node{
    // Mỗi node chứa 2 con trỏ
    struct Node* next;      // next: trỏ đến nút kế tiếp
    struct Node* prev;      // prev: trỏ đến nút liền trước
    struct ElementType e;   // biến e kiểu Element Type để lưu trữ dữ liệu
};

// Bí danh Typedef giúp cho Struct Node dễ đọc hơn 
typedef struct Node *List;          // thường dùng để chỉ đầu danh sách
typedef struct Node *Position;      // dùng để chỉ một nút cụ thể
typedef struct ElementType ElemenType;

// Pointer to an empty List = NULL

// Điểm bắt đầu cố định cho danh sách 
List create(){
    // cug cấp một nút tiêu đề cho header node
    Position header = malloc(sizeof(struct Node)); // cấp phat bộ nhớ với khối lượng đủ lớn để chứa một cấu trúc node
    // trả về con trỏ kiểu void* và được gán cho biến header có kiểu là Position (tức là structnode)
    header->next = NULL;    // Con trỏ next của nút tiêu đề được gán bằng NULL
    header-> prev = NULL;   // Tương tự
    return header;  // Trả về con trỏ header, đại diện cho danh sách liên kết đôi vừa mới được tạo
}

// Chèn một nút với dữ liệu e vào danh sách liên kết đôi, nếu p là null, nút mới sẽ được chèn ngay sau nút tiêu đề 
void Insert(List pL, struct ElementType e, Position p){
    Position newItem = (struct Node *)malloc(sizeof(struct Node));
    newItem->e = e; // Sao chép dữ liệu
    if (p == NULL )
        p = pL;
    newItem->next = p->next;
    newItem->prev = p;
    p->next = newItem;
    if (newItem->next != NULL)
        newItem->next->prev = newItem;
}

void show(List pL){
    while (pL != NULL) {
        printf("ID: %d                      Name: %s\n ", pL ->e.ID, pL->e.name);
        pL = pL->next;
    }
}

void del(List pL, Position p){
    if (p ==  NULL)
        return;

    p->prev->next = p->next;
    if (p->next != NULL)
        p->next->prev = p->prev;
    free(p);
    // Position prev_p = pL;
    // while (prev_p!=NULL && prev_p->next != p)
    //     prev_p = prev_p->next;
    // if (prev_p != NULL){
    //     prev_p->next = p->next;
    //     free(p);
    // }
}

Position findById(List pL, int id){
    pL = pL->next;
    while (pL != NULL && pL->e.ID != id)
        pL = pL->next;
    return pL;
}


int main(){

    List pL=create();
	struct ElementType e1, e2, e3;
	e1.ID = 1; e1.name = "Nguyen Van A";
	e2.ID = 2; e2.name = "Nguyen Van B";
	e3.ID = 3; e3.name = "Nguyen Van C";
	Insert(pL, e1, NULL);
	Insert(pL, e2, NULL);
	Insert(pL, e3, NULL);
	show(pL);

    printf("-------------Execute Delete----------- \n");
    
	Position p = findById(pL, 2);
	del(pL, p);
    show(pL);
	return 0;
}