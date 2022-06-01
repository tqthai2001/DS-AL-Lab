#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char name[256];
    char email[256];
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* root;

Node* makeNode(char* name, char* email){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name);
    strcpy(p->email,email);
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node* insert(Node* r, char* name, char* email){
    if(r == NULL) return makeNode(name,email);
    int c = strcmp(r->name,name);
    if(c == 0){
        printf("Student %s exists, do not insert\n",name); return r;
    }
    else if(c < 0){
        r->rightChild = insert(r->rightChild,name,email); return r;
    }
    else{
        r->leftChild = insert(r->leftChild,name,email); return r;
    }
}

Node* find(Node* r, char* name){
    if(r == NULL) return NULL;
    int c = strcmp(r->name,name);
    if(c == 0) return r;
    if(c < 0) return find(r->rightChild,name);
    return find(r->leftChild,name);
}

Node* findMin(Node* r){
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->leftChild);
    if(lmin != NULL) return lmin;
    return r;
}

Node* removeStudent(Node* r, char* name){
    if(r == NULL) return NULL;
    int c = strcmp(r->name,name);
    if(c > 0) r->leftChild = removeStudent(r->leftChild,name);
    else if(c < 0) r->rightChild = removeStudent(r->rightChild,name);
    else{
        if(r->leftChild != NULL && r->rightChild != NULL){
            Node* tmp = findMin(r->rightChild);
            strcpy(r->name,tmp->name);
            strcpy(r->email,tmp->email);
            r->rightChild = removeStudent(r->rightChild,tmp->name);
        }
        else{
            Node* tmp = r;
            if(r->leftChild == NULL) r = r->rightChild;
            else r = r->leftChild;
            free(tmp);
        }
    }
    return r;
}

void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

void load(char* filename){
    char name[256], email[256];
    FILE* f = fopen(filename,"r");
    if(f == NULL) printf("Can not open file!\n");
    root = NULL;
    while(!feof(f)){
        fscanf(f,"%s %s",name,email);
        root = insert(root,name,email);
    }
}


void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s, %s\n",r->name,r->email);
    inOrder(r->rightChild);
}

void inOrderF(Node* r, FILE* f){
    if(r == NULL) return;
    inOrderF(r->leftChild,f);
    fprintf(f,"%s %s\n",r->name,r->email);
    inOrderF(r->rightChild,f);
}

void printList(){
    inOrder(root);
    printf("\n");
}

void processStore(){
    char filename[256];
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    inOrderF(root,f);
    fclose(f);
}

void processLoad(){
    char filename[256];
    scanf("%s",filename);
    load(filename);
}

void processInsert(){
    char name[256], email[256];
    scanf("%s %s",name,email);
    root = insert(root,name,email);
}

void processFind(){
    char name[256];
    Node *temp;
    scanf("%s",name);
    temp = find(root,name);
    if(temp == NULL) printf("Not found %s!",name);
    else printf("Found %s with email: %s",name,temp->email);
}

void processRemove(){
    char name[256];
    scanf("%s",name);
    root = removeStudent(root,name);
}

int main(){
    int choice, run = 1;

    while(run){
        printf("\n________________________\n");
        printf("__________MENU__________\n\n");
        printf("1. Load\n");
        printf("2. Print Infor\n");
        printf("3. Find Infor\n");
        printf("4. Insert\n");
        printf("5. Remove\n");
        printf("6. Store Infor\n");
        printf("7. Exit\n");
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
            processFind();
            break;
            case 4:
            processInsert();
            break;
            case 5:
            processRemove();
            break;
            case 6:
            processStore();
            break;
            case 7:
            freeTree(root);
            run = 0; break;
            default:
            printf("Try Again!"); break;
        }
    }
}