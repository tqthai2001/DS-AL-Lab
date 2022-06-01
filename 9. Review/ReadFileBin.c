#include <stdio.h>
#include <stdlib.h>

typedef struct Contact{
    char name[30];
    char tel[10];
    char email[35];
}Contact;

typedef struct node{
    Contact data;
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

void enQueue(queue *q, Contact value){
    node *temp = (node*)malloc(sizeof(node));
    temp->data=value;
    temp->link=NULL;
    if(q->front == NULL) q->front = q->rear = temp;
    q->rear->link=temp;
    q->rear=temp;
}

void deQueue(queue *q, Contact *value){
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
    queue hangdoi;
    makeQueue(&hangdoi);
    Contact dulieu, dulieura;
    FILE *fin = fopen("program.bin", "rb");
    while(!feof(fin)){
        fread(&dulieu, sizeof(Contact), 1, fin);
        enQueue(&hangdoi, dulieu);
    }
    fclose(fin);
    FILE *fout = fopen("programx.bin", "wb");
    while(hangdoi.front != NULL){
        deQueue(&hangdoi, &dulieura);
        fwrite(&dulieura, sizeof(Contact), 1, fout);
    }
    fclose(fout);
}