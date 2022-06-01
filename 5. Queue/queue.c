#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void makeQueue(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(queue *q){
    return q->front == NULL;
}

void enQueue(queue *q, Contact value){
    node *temp = (node*)malloc(sizeof(node));
    temp->data=value;
    temp->link=NULL;
    if(isEmpty(q)) q->front = q->rear = temp;
    q->rear->link=temp;
    q->rear=temp;
}

void deQueue(queue *q, Contact *value){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        exit(0);
    }
    node *temp;
    *value = q->front->data;
    temp = q->front;
    q->front = q->front->link;
    free(temp);
}

void front(queue *q, Contact *value){
    *value = q->front->data;
}