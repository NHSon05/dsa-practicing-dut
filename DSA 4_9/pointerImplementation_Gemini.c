#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strdup()

// Defines the structure for data stored in each node
struct ElementType {
    int ID;
    char *name;
};

// Defines the structure for a node in the linked list
struct Node {
    struct Node *next;
    struct ElementType e;
};

// Typedefs for convenience
typedef struct Node *List;
typedef struct Node *Position;


// Corrected Insert function
// Inserts an element after position p, or at the head if p is NULL
void Insert(List *pL, struct ElementType e, Position p) {
    Position newItem = (struct Node *)malloc(sizeof(struct Node));

    // Deep copy the ElementType data
    newItem->e.ID = e.ID;
    newItem->e.name = strdup(e.name);

    // Case 1: Insert at the beginning of the list (p is NULL)
    if (p == NULL) {
        newItem->next = *pL;
        *pL = newItem; // Update the list head via pointer-to-pointer
    } 
    // Case 2: Insert after position p
    else {
        newItem->next = p->next;
        p->next = newItem;
    }
}

// Display function
void show(List pL) {
    if (pL == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("List contents:\n");
    while (pL != NULL) {
        printf("  ID: %d, Name: %s\n", pL->e.ID, pL->e.name);
        pL = pL->next;
    }
    printf("\n");
}

// Corrected Delete function (fixes head deletion and memory leaks)
void del(List *pL, Position p) {
    if (p == NULL || *pL == NULL) {
        return;
    }
    if (p == *pL) { // Deleting the head
        *pL = p->next;
        free(p->e.name);
        free(p);
    } else { // Deleting an inner node
        Position prev_p = *pL;
        while (prev_p != NULL && prev_p->next != p) {
            prev_p = prev_p->next;
        }
        if (prev_p != NULL) {
            prev_p->next = p->next;
            free(p->e.name);
            free(p);
        }
    }
}

// Find function
Position findById(List pL, int id) {
    while (pL != NULL && pL->e.ID != id) {
        pL = pL->next;
    }
    return pL;
}

// Frees all memory in the list


int main() {
    List myList = NULL;
    
    struct ElementType e1 = {1, "Alice"};
    struct ElementType e2 = {2, "Bob"};
    struct ElementType e3 = {3, "Charlie"};

    printf("--- Inserting items into an empty list ---\n");
    Insert(&myList, e1, NULL); // Insert first item
    show(myList);

    printf("--- Inserting an item at the head ---\n");
    Insert(&myList, e2, NULL); // Insert new head
    show(myList);

    printf("--- Inserting an item after an existing node ---\n");
    Position pos_e1 = findById(myList, 1);
    Insert(&myList, e3, pos_e1); // Insert "Charlie" after "Alice"
    show(myList);

    printf("--- Deleting an item ---\n");
    Position to_delete = findById(myList, 1);
    del(&myList, to_delete);
    show(myList);

    return 0;
}