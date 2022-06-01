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
    printf("Nhap ID san pham: ");
    fseek(stdin, 0, SEEK_END);
    gets(dulieu->id);

    printf("Nhap ten san pham: ");
    fseek(stdin, 0, SEEK_END);
    gets(dulieu->name);

    printf("Nhap gia san pham: ");
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &dulieu->price);

    printf("\n");
}

Node *CreateNode(Product dulieu){
    Node *p = (Node*) malloc(sizeof(Node));
    p->data=dulieu;
    p->pNext=NULL;
    p->pPrev=NULL;
    return p;
}

void ThemVaoCuoi(Product dulieu){
    Node *p;
    p = CreateNode(dulieu);
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
    printf("Nhap ID san pham: ");
    fseek(stdin, 0, SEEK_END);
    gets(tempID);

    int count = 0;
    for(Node *i = pHead; i != NULL; i=i->pNext){
        if (strcmp(tempID, i->data.id) == 0){
            count++;
            printf("Name: %s\nPrice: %d\n", i->data.name, i->data.price);
        }
    }
    if(count==0) printf("Not Found!\n");
}

void InDS(){
    if(pHead == NULL) printf("Empty List!\n");
    for(Node *i = pHead; i != NULL; i=i->pNext){
        printf("%s\t%s\t%d\n", i->data.id, i->data.name, i->data.price);
    }
}

void XoaDS(){
    while (pHead!=NULL)
    {
        Node *p = pHead;
        pHead = pHead->pNext;
        free(p);
    }
}

void ThemVaoN(Product dulieu){
    int n;
    Node *p = CreateNode(dulieu);
    printf("Nhap vi tri can them: ");
    scanf("%d", &n);
    Node *cur = pHead;
    for(int i=1;i<n;i++) cur=cur->pNext;
    p->pNext=cur->pNext;
    cur->pNext=p;
}

int main(){
    int choice, run = 1;
    Product dulieu, dulieuz;

    while(run){
        printf("________________________\n");
        printf("__________MENU__________\n\n");
        printf("1. Them Vao Cuoi\n");
        printf("2. In DS\n");
        printf("3. Tim Kiem\n");
        printf("4. Xoa DS\n");
        printf("5. Them Vao Vi Tri N\n");
        printf("6. Thoat\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("________________________\n\n");
        
        switch(choice){
            case 1:
            {
                int m;
                printf("Nhap so san pham can them: ");
                scanf("%d", &m);
                printf("\n");
                for(int i=0; i<m; i++){
                    NhapDuLieu(&dulieu);
                    ThemVaoCuoi(dulieu);
                }
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
            NhapDuLieu(&dulieuz);
            ThemVaoN(dulieuz);
            break;
            case 6:
            run = 0; break;
            default:
            printf("Try Again!"); break;
        }
    }
}