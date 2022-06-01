#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Product
{
    char id[20];
    char name[80];
    int price;
}Product;

typedef struct Node
{
    Product data;
    struct Node *pNext, *pPrev;
}Node;
Node *pHead, *pTail;

void NhapDuLieu(Product *dulieu){
    printf("Enter ID, Name, Price: ");
    scanf("%s %s %d", dulieu->id, dulieu->name, &dulieu->price);
}

Node *makeNode(Product dulieu){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data=dulieu;
    p->pNext=NULL;
    p->pPrev=NULL;
    return p;
}

void ThemVaoCuoi(Product dulieu){
    Node *p = makeNode(dulieu);
    if(pHead == NULL){
        pHead = pTail = p;
    }
    else{
        p->pPrev=pTail;
        pTail->pNext=p;
        pTail=p;
    }
}

void TimKiem(){
    char tempID[20];
    int count = 0;
    printf("Enter ID: ");
    fseek(stdin, 0, SEEK_END);
    gets(tempID);

    for(Node *i = pHead; i != NULL; i=i->pNext){
        if (strcmp(tempID, i->data.id) == 0){
            printf("Name: %s\nPrice: %d\n", i->data.name, i->data.price);
            count++;
        }
    }
    if(count==0) printf("Not Found!\n");
}

void InDS(){
    if(pHead == NULL) printf("Empty!\n");
    for(Node *i = pHead; i != NULL; i=i->pNext){
        printf("%s\t%s\t%d\n", i->data.id, i->data.name, i->data.price);
    }
}

void XoaDS(){
    while(pHead!=NULL)
    {
        Node *p = pHead;
        pHead = pHead->pNext;
        free(p);
    }
}

int main(){
    int choice, run = 1;
    int m;
    Product dulieu;

    while(run){
        printf("________________________\n");
        printf("__________MENU__________\n\n");
        printf("1. Them Vao Cuoi\n");
        printf("2. In DS\n");
        printf("3. Tim Kiem\n");
        printf("4. Xoa DS\n");
        printf("5. Thoat\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("________________________\n\n");
        
        switch(choice){
            case 1:
            printf("Nhap So San Pham: ");
            scanf("%d", &m);
            for(int i=0; i<m; i++){
                NhapDuLieu(&dulieu);
                ThemVaoCuoi(dulieu);
            }
            break;

            case 2:
            InDS();
            break;

            case 3:
            TimKiem();
            break;

            case 4:
            XoaDS();
            break;

            case 5:
            run = 0; break;
            default:
            printf("Try Again!\n"); break;
        }
    }
}