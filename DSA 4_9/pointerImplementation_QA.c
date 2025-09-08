#include <stdio.h>
#include <stdlib.h>

struct ElementType{
	int ID;
	char *name;
};

struct Node{
	struct Node* next;
	struct ElementType e;
};

typedef struct Node *List;
typedef struct Node *Position;
typedef struct ElementType ElementType;

List create(){
	Position header = malloc(sizeof(struct Node));
	header->next = NULL;
	return header;
}
void Insert (List pL, struct ElementType e, Position p) {
	Position newItem= malloc(sizeof(struct Node));
    newItem->e = e;
    if (p == NULL )
        p = pL;
    
	newItem->next = p->next;
	p->next = newItem;
}

void del(List pL, Position p) {
	if (p == NULL)
	    return;
	Position prev_p = pL;
	while (prev_p!=NULL && prev_p->next !=p)
		prev_p = prev_p->next;
	if (prev_p != NULL){
		prev_p->next = p->next;
		free(p);
	}
}

Position findById(List pL, int id){
	pL = pL->next;
	while (pL != NULL && pL ->e.ID != id)
	       pL = pL->next;
	return pL;
}
void show(List pL){
	pL=pL->next;
	while (pL != NULL) {
		printf("Id: %d    Name: %s\n", pL->e.ID, pL->e.name);
		pL = pL->next;
		
	}
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
//	Position p = findById(pL, 2);
	//del(pL, p);
	return 0;
}	