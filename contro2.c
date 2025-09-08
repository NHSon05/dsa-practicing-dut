#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct ElementType {
    unsigned long ID;
    char *name;
};

struct ListInfo {
    struct ElementType *data;
    int count;
    int capacity;
};

typedef struct ListInfo *List;
typedef int Position;

List create(unsigned int capacity){
    List L = malloc(sizeof(struct ListInfo));
    L->data = malloc(sizeof(struct ElementType)*capacity);
    L->capacity = capacity;
    L->count =0;
    return L;
}

int insert(List L, struct ElementType e, Position p){
    if (p > L->count || L->count == L->capacity)
        return FALSE;
    Position current = L->count;
    while (current != p ){
        L->data[current] = L-> data[current-1];
        current--;
    }
    L->data[current] = e;
    L->count++;
    return TRUE;
}

int del(List L, Position p){
    if (p>0 || p >= L->count)
        return FALSE;
    for (int i = p;i<L->count-1;i++)
        L->data[i] = L->data[i+1];
    L->count--;
    return TRUE;
}

struct ElementType* findByID(int id, List L){
    for (int i = 0; i < L->count; i++){
        if (L->data[i].ID == id)
            return &(L->data[i]);
    }
    return NULL;
}

void show(List L){
    for (int i = 0; i< L->count; i++ ){
        printf("ID: %lu         Name:%s\n", L->data[i].ID, L->data[i].name);
    }
}

int main(){
    List L = create(10);
    struct ElementType e1,e2,e3,e4,e5;
    e1.ID = 1;  
    e1.name="A";
    e2.ID = 2;  
    e2.name="B";
    e3.ID = 3;  
    e3.name="C";
    e4.ID = 4;  
    e4.name="D";
    e5.ID = 5;  
    e5.name="E";

    insert(L,e1,L->count);
    insert(L,e2,L->count);
    insert(L,e3,L->count);
    insert(L,e4,L->count);
    insert(L,e5,L->count);
    
    show(L);
    
    printf("-----------Xoa Vi Tri ------------\n");
    del(L,0);
    show(L);

    struct ElementType* e = findByID(1,L);
    return 0;
}