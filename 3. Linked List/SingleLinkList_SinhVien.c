#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ID_LENGTH 10
#define NAME_LENGTH 30

typedef struct Student_t
{
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
    int grade;
    struct Student_t *pNext;
}Student;

Student *CreateNode(){
    Student *p = (Student*)malloc(sizeof(Student));
    printf("Enter ID: ");
    fseek(stdin, 0, SEEK_END);
    gets(p->id);
    printf("Enter Name: ");
    fseek(stdin, 0, SEEK_END);
    gets(p->name);
    printf("Enter Grade: ");
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &(p->grade));
    p->pNext=NULL;
    return p;
}

Student *Insert(Student *pHead, Student *p){
    if(pHead == NULL) return p;
    if(pHead->grade <= p->grade)
    {
        p->pNext = pHead;
        return p;
    }
    Student *pCur, *pPrev;
    pCur = pHead;
    while (pCur != NULL && p->grade <= pCur->grade)
    {
        pPrev = pCur;
        pCur = pCur->pNext;
    }
    p->pNext = pPrev->pNext;
    pPrev->pNext = p;
    // pPrev->pNext = p;
    // p->pNext = pCur;
    return pHead;
}

Student *Searching(Student *pHead, char tempID[]){
    for(Student *i = pHead; i != NULL; i = i->pNext)
    {
        if(strcmp(tempID, i->id) == 0) return i;
    }
    return NULL;
}

Student *Delete(Student *pHead, char tempID[]){
    Student *pCur = NULL;
    Student *pPrev = NULL;
    // if (pHead = NULL) return pHead;
    if (strcmp(tempID, pHead->id) == 0)
    {   
        pCur = pHead;
        pHead = pHead->pNext;
        free(pCur);
        return pHead;
    }
    for(pCur = pHead; pCur != NULL; pCur = pCur->pNext){
        if(strcmp(pCur->id, tempID)==0) break;
        pPrev=pCur;
    }
    if(pCur != NULL){
        pPrev->pNext = pCur->pNext;
        free(pCur);
    }
    return pHead;
}

Student *ChangeGrade(Student *pHead, char tempID[], int newgrade){
    Student *p = Searching(pHead, tempID);
    Student *new = (Student*)malloc(sizeof(Student));
    strcpy(new->name, p->name);
    strcpy(new->id, p->id);
    new->grade=newgrade;
    pHead = Delete(pHead, tempID);
    pHead = Insert(pHead, new);
    return pHead;
}

void Print(Student *pHead){
    if(pHead == NULL) printf("Empty!\n");
    for(Student *i = pHead; i != NULL; i = i->pNext)
    {
        printf("%s\t%s\t%d\n", i->id, i->name, i->grade);
    }
}

int main(){
    int choice, run = 1;
    Student *pHead = NULL;
    char id[ID_LENGTH];
    int n;
    Student *student, *hs;

    while(run){
        printf("________________________\n");
        printf("__________MENU__________\n\n");
        printf("1. Insert\n");
        printf("2. Print\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Change Grade\n");
        printf("6. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("________________________\n\n");
        
        switch(choice){
            case 1:
            {
            student = CreateNode();
            pHead = Insert(pHead, student);
            break;
            }
            case 2:
            Print(pHead);
            break;
            case 3:
            {
            printf("Enter ID: ");
            fseek(stdin, 0, SEEK_END);
            gets(id);
            hs = Searching(pHead, id);
            if(hs != NULL)
            {
                printf("%s\t%d\n", hs->name, hs->grade);
            }
            else printf("Not Found!\n");
            break;
            }
            case 4:
            {
            printf("Enter ID: ");
            fseek(stdin, 0, SEEK_END);
            gets(id);
            pHead = Delete(pHead, id);
            break;
            }
            case 5:
            {
            printf("Enter ID: ");
            fseek(stdin, 0, SEEK_END);
            gets(id);
            printf("Enter New Grade: ");
            scanf("%d", &n);
            pHead = ChangeGrade(pHead, id, n);
            break;
            }
            case 6:
            run = 0; break;
            default:
            printf("Try Again!"); break;
        }
    }
}