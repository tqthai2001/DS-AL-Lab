#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

typedef struct queue{
    node *front;
    node *rear;
}queue;

void makeQueue(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void enQueue(queue *q, int value){
    node *temp = (node*)malloc(sizeof(node));
    temp->data=value;
    temp->link=NULL;
    if(q->front == NULL) q->front = q->rear = temp;
    q->rear->link=temp;
    q->rear=temp;
}

void deQueue(queue *q, int *value){
    if(q->front != NULL){
        node *temp;
        *value = q->front->data;
        temp = q->front;
        q->front = q->front->link;
        free(temp);
    }
    else printf("Error! Queue is empty!\n");
}

int main(){
    int n,m;
    int count = 0;
    queue hangdoi;
    makeQueue(&hangdoi);
    do{
        printf("Enter Number: ");
        scanf("%d", &n);
        count += 1;
        if(count > 10){
            deQueue(&hangdoi, &m);
            printf("Out: %d\n", m);
        }
        enQueue(&hangdoi, n);
    }
    while (n!=0);
}