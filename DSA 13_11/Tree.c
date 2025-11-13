#include <stdio.h>
#include <stdlib.h>

struct TreeNodeInfo {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
};

typedef struct TreeNodeInfo *BST;
typedef struct TreeNodeInfo *TreeNode;

void insert(BST *T, int key){
    TreeNode x,y,z;
    z  = malloc(sizeof(struct TreeNodeInfo));
    z -> key = key;
    z -> left = NULL;
    z -> right = NULL;
    z -> parent = NULL;

    y = NULL;
    x = *T;
    while (x != NULL){
        y = x;
        if (x->key > z->key)
            x = x -> left;
        else x = x -> right;  
    }
    z -> parent = y;
    if (y == NULL){
        *T = z;
    } else if (y->key > z -> key)
        y -> left = z;
    else y -> right = z;
}
void preoder_travesal(BST T){
    if (T!=NULL){
        printf("%d ", T->key);
        preoder_travesal(T->left);
        preoder_travesal(T->right);
    }
}

void inoder_travesal(BST T){
    if (T!=NULL){
        inoder_travesal(T->left);
        printf("%d ", T->key);
        inoder_travesal(T->right);
    }
}

void postoder_travesal(BST T){
    if (T!=NULL){
        postoder_travesal(T->left);
        postoder_travesal(T->right);
        printf("%d ", T->key);
    }
}
int main(){
    BST T = NULL;
    insert(&T, 12);
    insert(&T, 5);
    insert(&T, 2);
    insert(&T, 9);
    insert(&T, 15);
    insert(&T, 7);
    insert(&T, 11);
    insert(&T, 20);
    insert(&T, 19);
    insert(&T, 6);
    insert(&T, 3);
    insert(&T, 10);
    preoder_travesal(T);
    printf("\n");
    inoder_travesal(T);
    printf("\n");
    postoder_travesal(T);
    return 0;
}