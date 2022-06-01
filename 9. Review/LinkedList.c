#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[255];
    char email[255];
    char tel[255];
}Contact;

typedef struct Node{
    Contact data;
    struct Node *next;
}Node;
Node *root;

void NhapDuLieu(Contact *dulieu){
    printf("Enter Name, Email, Tel: ");
    scanf("%s %s %s", dulieu->name, dulieu->email, dulieu->tel);
}

Node *makeNode(Contact dulieu){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = dulieu;
    p->next = NULL;
    return p;
}

Node *ThemVaoDau(Node *r, Node *p){
    if(r == NULL) return p;
    p->next = r;
    r = p;
    return r;
}

void InDS(Node *r){
    if(r == NULL) printf("Empty!\n");
    for(Node *i=r; i!=NULL; i=i->next){
        printf("%s\t%s\t%s\n", i->data.name, i->data.email, i->data.tel);
    }
}

Node *TimKiem(Node *r){
    char temp_name[255];
    printf("Enter Name: ");
    scanf("%s", temp_name);
    int count = 0;
    for(Node *i = r; i != NULL; i = i->next){
        if(strcmp(temp_name, i->data.name) == 0){
            count += 1;
            return i;
        }
    }
    if(count == 0) return NULL;
}

void processTimKiem(){
    Node *p = TimKiem(root);
    if(p == NULL) printf("Not Found!\n");
    else printf("Email: %s\nTel: %s\n", p->data.email, p->data.tel);
}

Node *DaoNguoc(Node *r){
    Node *pPrev = NULL;
    while (r != NULL)
    {
        Node *pNext = r->next;
        r->next = pPrev;
        pPrev = r;
        r = pNext;
    }
    r = pPrev;
    return r;
}

Node *XoaDS(Node *r){
    while (r != NULL)
    {
        Node *temp = r;
        r = r->next;
        free(temp);
    }
    return r;
}

int main(){
    int choice, run = 1;
    Contact data;
    int n;

    while(run){
        printf("\n________________________\n");
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
            printf("Nhap So Nguoi Muon Them: ");
            scanf("%d", &n);
            for(int m=0; m<n; m++){
                NhapDuLieu(&data);
                Node *cur = makeNode(data);
                root = ThemVaoDau(root, cur);
            }
            break;

            case 2:
            InDS(root);
            break;

            case 3:
            processTimKiem();
            break;

            case 4:
            root = DaoNguoc(root);
            break;

            case 5:
            root = XoaDS(root);
            break;

            case 6:
            run = 0; break;
            
            default:
            printf("Try Again!"); break;
        }
    }
}