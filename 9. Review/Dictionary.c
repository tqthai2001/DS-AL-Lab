#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char eng[256];
    char vie[256];
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* root;

Node* makeNode(char* eng, char* vie){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->eng,eng);
    strcpy(p->vie,vie);
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node* insert(Node* r, char* eng, char* vie){
    if(r == NULL) return makeNode(eng,vie);
    int c = strcmp(r->eng,eng);
    if(c == 0){
        printf("The word %s exists, do not insert\n",eng); return r;
    }
    else if(c < 0){
        r->rightChild = insert(r->rightChild,eng,vie); return r;
    }
    else{
        r->leftChild = insert(r->leftChild,eng,vie); return r;
    }
}

// Doc file

void load(char* filename){
    char eng[256], vie[256];
    FILE* f = fopen(filename,"r");
    if(f == NULL) printf("Can not open file!\n");
    root = NULL;
    while(!feof(f)){
        fscanf(f,"%s %s",eng,vie);
        printf("%s %s\n",eng,vie);
        root = insert(root,eng,vie);
    }
}

void processLoad(){
    char filename[256];
    printf("Enter filename: ");
    scanf("%s",filename);
    load(filename);
}

// Duyet cay con trai - cha - cay con phai

void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s\n",r->eng);
    inOrder(r->rightChild);
}

void printList(){
    if(root == NULL) printf("Empty!");
    inOrder(root);
    printf("\n");
}

// Tim kiem

Node* translate(Node* r, char* eng){
    if(r == NULL) return NULL;
    printf("%s\n",r->eng);
    int c = strcmp(r->eng,eng);
    if(c == 0) return r;
    if(c < 0) return translate(r->rightChild,eng);
    return translate(r->leftChild,eng);
}

void processTranslate(){
    char eng[256];
    Node *temp;
    printf("Enter word: ");
    scanf("%s",eng);
    temp = translate(root,eng);
    if(temp == NULL) printf("Khong tim thay tu can tra!",eng);
    else printf("%s mean: %s",eng,temp->vie);
}

// Them tu moi

void processInsert(){
    char eng[256], vie[256];
    printf("Nhap tu ENGLISH VIETNAMESE: ");
    scanf("%s %s",eng,vie);
    root = insert(root,eng,vie);
}

// Xoa toan bo cay

void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

int main(){
    int choice, run = 1;

    while(run){
        printf("\n________________________\n");
        printf("__________MENU__________\n\n");
        printf("1. Load\n");
        printf("2. Print\n");
        printf("3. Translate\n");
        printf("4. Add\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("________________________\n\n");
        
        switch(choice){
            case 1:
            processLoad();
            break;
            case 2:
            printList();
            break;
            case 3:
            processTranslate();
            break;
            case 4:
            processInsert();
            break;
            case 5:
            freeTree(root);
            run = 0; break;
            default:
            printf("Try Again!"); break;
        }
    }
}