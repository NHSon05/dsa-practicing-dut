#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define EMPTY -1

struct ElementType {
    int id;
    char *name;
};

struct QueueInfo{
    struct ElementType *data;
    int capacity;
    int count;
    int rear;
    int front;
};

typedef struct QueueInfo *Queue;
// Create Queue
Queue create(int capacity){
    // Cap phat bo nho
    Queue Q = malloc(sizeof(struct QueueInfo));
    Q -> capacity = capacity;
    Q -> count = 0;
    Q -> rear = 7;
    Q -> front = 8;
    Q -> data = malloc(sizeof(struct ElementType) * capacity);
    return Q;
}
// Kiểm tra queue đã full chưa
int isFull(Queue Q){
    return Q -> capacity == Q -> count;
}
// Kiểm tra queue có rỗng không
int isEmpty(Queue Q){
    return Q -> count == 0;
}
// Increase queue 
// Hàm xử lý việc tăng chỉ số trong mảng vòng
int increase(Queue Q, int value){
    if (++value == Q->capacity){
        value = 0;
    }
    return value;
}
// Thao thác chèn phần tử e vào hàng đợi
int enqueue(Queue Q, struct ElementType e){
    if (isFull(Q)){
        return FALSE;
    }
    Q -> rear = increase(Q, Q->rear);
    Q -> data[Q->rear] = e;
    Q -> count++;
    return TRUE;
}

struct ElementType dequeue(Queue Q){
    if (isEmpty(Q)){
        struct ElementType e;
        e.id = EMPTY;
        return e;
    }
    struct ElementType temp = Q->data[Q->front];
    Q->front = increase(Q,Q->front);
    Q->count--;
    return temp;
}

int main(){
    Queue Q = create(10);
    struct ElementType e;
    e.id = 2;
    enqueue(Q,e);
    e.id = 4;
    enqueue(Q,e);
    e.id = 1;
    enqueue(Q,e);
    e.id = 3;
    enqueue(Q,e);

    while (Q->count > 0){
        e = dequeue(Q);
        printf("ID = %d\n",e.id);
    }
    return 0;
}