#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple linked-list stack for chars
typedef struct Node {
    char c;
    struct Node *next;
} Node;

typedef Node* Stack;()

Stack push(Stack top, char c){
    Node *n = malloc(sizeof(Node));
    if (!n){
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    n->c = c;
    n->next = top;
    return n;
}

Stack pop(Stack top, char *out){
    if (!top) return NULL;
    if (out) *out = top->c;
    Node *next = top->next;
    free(top);
    return next;
}

int isEmpty(Stack top){
    return top == NULL;
}

int matches(char open, char close){
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isBalanced(const char *s){
    Stack st = NULL;
    for (int i = 0; s[i]; ++i){
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{'){
            st = push(st, ch);
        } else if (ch == ')' || ch == ']' || ch == '}'){
            if (isEmpty(st)){
                // closing with empty stack
                while (st) { char tmp; st = pop(st, &tmp); }
                return 0;
            }
            char topc = st->c;
            st = pop(st, &topc); // pop
            if (!matches(topc, ch)){
                while (st) { char tmp; st = pop(st, &tmp); }
                return 0;
            }
        }
    }
    int balanced = isEmpty(st);
    while (st) { char tmp; st = pop(st, &tmp); }
    return balanced;
}

int main(void){
    char line[1024];
    printf("Enter expression (or EOF to quit):\n");
    while (fgets(line, sizeof(line), stdin)){
        // remove trailing newline
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0) { puts("Empty input"); continue; }
        if (isBalanced(line))
            printf("Balanced\n");
        else
            printf("Not Balanced\n");
        printf("Enter expression (or EOF to quit):\n");
    }
    return 0;
}
