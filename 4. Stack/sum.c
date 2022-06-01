#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node *push(node *p, int value){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->link = p;
    p = temp;
    return p;
}

node *pop(node *p, int *value){
    node *temp;
    if (p == NULL){
        printf("Stack is empty!\n");
        exit(0);
    }
    *value = p->data;
    temp = p;
    p = p->link;
    free(temp);
    return p;
}

int main(){
    struct node *top1 = NULL;
    struct node *top2 = NULL;
    struct node *top3 = NULL;
    int value1, value2, value3;
    int temp = 0;
    char first[255], second[255];

    printf("Nhap so thu nhat: ");
    scanf("%s", first);
    for (int i = 0; i < strlen(first); i++){
        value1 = first[i] - 48;
        top1 = push(top1, value1);
    }

    printf("Nhap so thu hai: ");
    scanf("%s", second);
    for (int i = 0; i < strlen(second); i++){
        value2 = second[i] - 48;
        top2 = push(top2, value2);
    }

    while (top1 != NULL || top2 != NULL || temp != 0){
        if (top1 == NULL) value1 = 0;
        else top1 = pop(top1, &value1);

        if (top2 == NULL) value2 = 0;
        else top2 = pop(top2, &value2);

        value3 = value1 + value2 + temp;

        if (value3 >= 10){
            value3 = value3 - 10;
            temp = 1;
        }
        else temp = 0;
        top3 = push(top3, value3);
    }
    printf("Tong: ");
    while (top3 != NULL){
        top3 = pop(top3, &value3);
        printf("%d", value3);
    }
    printf("\n");
}