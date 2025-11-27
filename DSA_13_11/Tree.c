#include <stdio.h>
#include <stdlib.h>

struct TreeNodeInfo
{
    int key;
    struct TreeNodeInfo *l;
    struct TreeNodeInfo *r;
    struct TreeNodeInfo *p;
};
typedef struct TreeNodeInfo *BST;
typedef struct TreeNodeInfo *TreeNode;

void insert(BST *T, int key)
{
    TreeNode x, y, z;
    // Create new TreeNode
    z = malloc(sizeof(struct TreeNodeInfo));
    z->key = key;
    z->l = NULL; // trỏ vào bên phải
    z->r = NULL; // trỏ vào bên trái
    z->p = NULL; // trỏ vào cha

    // Fine index to insert
    y = NULL;
    x = *T;

    // Duyet cay
    while (x != NULL)
    {
        y = x;
        if (key < x->key)
        {
            x = x->l;
        }
        else
            x = x->r;
    }
    // Khi thoát khỏi while
    z->p = y;
    // y == NULL thì z là node gốc
    if (y == NULL)
    {
        *T = z;
    }
    else if (key < y->key)
    {
        y->l = z;
    }
    else
        y->r = z;
}

// Tree traversal function
void preoder_travesal(BST T)
{
    if (T != NULL)
    {
        printf("%d ", T->key);
        preoder_travesal(T->l);
        preoder_travesal(T->r);
    }
}
TreeNode minimize(TreeNode x)
{
    if (x == NULL)
        return NULL;
    while (x->l != NULL)
    {
        x = x->l;
    }
    return x;
}
TreeNode maximize(TreeNode x)
{
    if (x == NULL)
    {
        return NULL;
    }
    while (x->r != NULL)
    {
        x = x->r;
    }
    return x;
}

TreeNode successor(TreeNode x)
{
    if (x->l != NULL)
    {
        return minimize(x->r);
    }
    TreeNode y = x->p; // bắt đầu từ nút cha
    while (y != NULL && x == y->r)
    {
        x = y;    // cập nhật x lên vị trí của y
        y = y->p; // Cập nhật y lên vị trí cha của y
    }
    return y;
}

TreeNode del_treenode(BST *T, TreeNode z)
{
    TreeNode y, x;
    if (z->l == NULL || z->r == NULL)
        y = z;
    else
        y = successor(z);
    if (y->l != NULL)
        x = y->l;
    else
        x = y->r;
    if (x != NULL)
        x->p = y->p;
    if (y->p == NULL)
        *T = x;
    else if (y == y->p->l)
        y->p->l = x;
    else
        y->p->r = x;
    if (y != z)
        z->key = y->key;
}
// Find and return a point contain this key
TreeNode search(TreeNode x, int key)
{
    if (x == NULL || x->key == key)
    {
        return x;
    }
    if (x->key > key)
    {
        search(x->l, key);
    }
    else
        search(x->r, key);
}

int main()
{
    BST T = NULL;
    insert(&T, 12), insert(&T, 5);
    insert(&T, 18), insert(&T, 2);
    insert(&T, 9), insert(&T, 15);
    insert(&T, 19), insert(&T, 13);
    insert(&T, 17);
    preoder_travesal(T);
    printf("\n");
    printf("Giá trị lớn nhất là:%d\n", maximize(T)->key);
    printf("Giá trị nhỏ nhất là:%d", minimize(T)->key);
    printf("\n");
    TreeNode succ = successor(T);
    if (succ != NULL)
        printf("Successor of %d is %d\n", T->key, succ->key);
    TreeNode x = search(T, 17);
    if (x != NULL)
    {
        succ = successor(x);
        if (succ != NULL)
            printf("\nSuccessor of %d is %d\n", x->key, succ->key);
    }
    x = search(T, 12);
    del_treenode(&T, x);
    printf("\n");
    preoder_travesal(T);
    return 0;
}