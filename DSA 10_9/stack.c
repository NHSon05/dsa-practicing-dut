#include <stdio.h>
#include <stdlib.h>
// #define TRUE 1
// #define FALSE 0
#define EMPTY -1

struct ElementType {
    int id;
    char *name;
};

struct StackRecord{
    int capacity;
    int count;
    struct ElementType *data;
};

typedef struct StackRecord *Stack;

int isFull(Stack S){
    return S->count == S->capacity;
};

int isEmpty(Stack S){
    return S->count == 0;
};

Stack create_stack(int capacity){
    Stack S = malloc(sizeof(struct StackRecord));
    S->capacity = capacity;
    S->count = 0;
    S->data = malloc(sizeof(struct ElementType) * capacity);
    return S;
}

void push(Stack S, struct ElementType e){
    if (isFull(S)){
        printf("The stack is full");
        return;
    } 
    S->data[S->count] = e;
    S->count++;
}

struct ElementType pop(Stack S){
    // struct ElementType empty = { .id = -1, .name = NULL };
    if (isEmpty(S)){
        printf("The stack is empty!\n");
        struct ElementType temp;
        temp.id = EMPTY;
        return temp;
    }

    S->count--;
    return S->data[S->count];
}

int main(){
    Stack S = create_stack(100);
    struct ElementType e1, e2, e3, e;
    e1.id = 1;  e1.name = "Nguyen Van A";
    e2.id = 2;  e2.name = "Nguyen Van B";
    e3.id = 3;  e3.name = "Nguyen Van C";

    push(S, e1);
    push(S, e2);
    push(S, e3);

    e = pop(S);
    if (e.id != EMPTY) printf("ID: %d    Name:%s\n", e.id, e.name);
    e = pop(S);
    if (e.id != EMPTY) printf("ID: %d    Name:%s\n", e.id, e.name);
    e = pop(S);
    if (e.id != EMPTY) printf("ID: %d    Name:%s\n", e.id, e.name);
    e = pop(S);
    if (e.id != EMPTY) printf("ID: %d    Name:%s\n", e.id, e.name);
    e = pop(S);
    if (e.id != EMPTY) printf("ID: %d    Name:%s\n", e.id, e.name);
    e = pop(S);
    if (e.id != EMPTY) printf("ID: %d    Name:%s\n", e.id, e.name);
    
    return 0;
}