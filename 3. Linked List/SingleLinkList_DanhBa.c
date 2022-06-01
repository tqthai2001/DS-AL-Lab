#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    char email[30];
    int tel;
}Contact_t;

typedef struct Node_t{
    Contact_t data;
    struct Node_t *pNext;
}Node_t;

typedef struct{
    Node_t *pHead;
    Node_t *pTail;
}List_t;

Node_t *CreateNode(Contact_t dulieu){
    Node_t *p=(Node_t*) malloc(sizeof(Node_t));
    p->data=dulieu; // ~ (*p).data=dulieu
    p->pNext=NULL;
    return p; // trả về địa chỉ của node mới tạo
}

void ThemVaoDau(List_t *list, Node_t *p){
    if(list->pHead==NULL) list->pHead = list->pTail = p;
    else{
        p->pNext=list->pHead;
        list->pHead=p;
    }
}

void NhapDuLieu(Contact_t *dulieu){
    printf("Enter Name: ");
    fseek(stdin,0,SEEK_END);
    gets(dulieu->name);

    printf("Enter Email: ");
    fseek(stdin,0,SEEK_END);
    gets(dulieu->email);

    printf("Enter Tel: ");
    fseek(stdin,0,SEEK_END);
    scanf("%d", &dulieu->tel);
}

void XuatDS(List_t list){
    if(list.pHead==NULL) printf("Empty!\n");
    for(Node_t *i=list.pHead; i!= NULL; i=i->pNext){
        printf("%s\t%s\t%d\n", (i->data).name, (i->data).email, (i->data).tel);
    }
}

void TimKiem(List_t list){
    char findname[20];
    int count = 0;
    printf("Enter Name Need To Find: ");
    fseek(stdin,0,SEEK_END);
    gets(findname);
    for(Node_t *i=list.pHead; i!= NULL; i=i->pNext){
        if(strcmp(findname, (i->data).name)==0){
            printf("Tel: %d\tEmail: %s\n", (i->data).tel, (i->data).email);
            count += 1;
        }
    }
    if(count==0) printf("Not Found!\n");
}

// void DaoNguoc(List_t *list){
//     Node_t *prev = NULL;
//     while(list->pHead != NULL){
//         Node_t *next = (list->pHead)->pNext;
//         (list->pHead)->pNext = prev;
//         prev = list->pHead;
//         list->pHead = next;
//     }
//     list->pHead = prev;
//     list->pTail = list->pHead;
//     while((list->pTail)->pNext != NULL){
//         list->pTail = (list->pTail)->pNext;
//     }
// }

void DaoNguoc(List_t *list){
    Node_t *p1 = list->pHead;
    Node_t *p2 = (list->pHead)->pNext;
    p1->pNext=NULL;
    while (p2 != NULL)
    {
        p1=p2;
        p2=p2->pNext;
        p1->pNext=list->pHead;
        list->pHead=p1;
    }
}

void XoaDS(List_t *list){
    while(list->pHead != NULL){
        Node_t *p = list->pHead;
        list->pHead = (list->pHead)->pNext;
        free(p);
    }
}

int main(){
    int choice, run = 1;
    List_t l;
    Contact_t dulieu;
    l.pHead = NULL;
    l.pTail = NULL;

    while(run){
        printf("________________________\n");
        printf("__________MENU__________\n\n");
        printf("1. Them Vao Dau\n");
        printf("2. In DS\n");
        printf("3. Tim Kiem\n");
        printf("4. Dao Nguoc\n");
        printf("5. Xoa DS\n");
        printf("6. Thoat\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("________________________\n\n");
        
        switch(choice){
            case 1:
            NhapDuLieu(&dulieu);
            Node_t *p;
            p = CreateNode(dulieu);
            ThemVaoDau(&l, p); // &l là địa chỉ của l còn giá trị của p là 1 địa chỉ của node được p trỏ đến
            break;
            case 2:
            XuatDS(l);
            break;
            case 3:
            TimKiem(l);
            break;
            case 4:
            DaoNguoc(&l);
            break;
            case 5:
            XoaDS(&l);
            break;
            case 6:
            run = 0; break;
            default:
            printf("Try Again!"); break;
        }
    }
}