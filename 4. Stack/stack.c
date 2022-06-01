#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty(node *p){
    if (p == NULL) return 1;
    return 0;
}

int size(node *p){
    int count = 0;
    for(node *i = p; i != NULL; i=i->link){
        count += 1;
    }
    return count;
}

node *push(node *p, int value){
    node *temp = (node*)malloc(sizeof(node));
    temp->data=value;
    temp->link=p;
    p=temp;
    return p;
}

node *pop(node *p, int *value){
    node *temp;
    if(isEmpty(p)){
        printf("Stack is empty!\n");
        exit(0);
    }
    *value=p->data;
    temp=p;
    p=p->link;
    free(temp);
    return p;
}

node *top(node *p, int *value){
    *value=p->data;
    return p;
}