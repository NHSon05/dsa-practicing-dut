#include <stdio.h>
#include <stdlib.h>


struct ElementType {
    int id;
    char *name;
};

struct StackRecord{
    int capacity;
    int count;
    struct ElementType *data;
}