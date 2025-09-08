#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Symbol {
    const char *name;
    unsigned long val;
};

struct Node {
    struct Node *next;
    struct Symbol *element;
};



struct Node *nodeA;
struct Node *nodeB;
struct Node *nodeC;
struct Node *nodeP;

int main () {
    struct Symbol oneSym;
    oneSym.name = "one";
    oneSym.val = 1;

    struct Symbol twoSym;
    twoSym.name = "two";
    twoSym.val = 2;

    struct Symbol threeSym;
    twoSym.name = "three";
    twoSym.val = 3;

    // nodeA = malloc(sizeof(struct Node));
    // nodeB = malloc(sizeof(struct Node));
    // nodeC = malloc(sizeof(struct Node));

    nodeA = new Node;
    nodeB = new Node;
    nodeC = new Node;

    nodeA->next = nodeB;
    nodeA->element = &oneSym;

    nodeB->next = nodeC;
    nodeB->element = &twoSym;

    nodeC->next = NULL;
    nodeC->element = &threeSym;

    nodeP = nodeA;

    while (nodeP != NULL) {
        printf("Name: %s        Value: %lu\n", nodeP->element-> name, nodeP->element->val);
        nodeP = nodeP->next;
    }

    cout << "hello world";

    struct _ListInfo {
        ElementType *theArray;
        int count;
        int maxsize;
    }

    typedef struct ListInfo *List;
    typedef int Position;

    return 0;
}