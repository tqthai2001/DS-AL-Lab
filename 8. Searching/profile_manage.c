#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Profile
{
    char name[256];
    char email[256];
}Profile;

Profile students[MAX];
int n = 0;

// void insert(char* name, char* email){
//     // maintain increasing order of name
//     int i = n-1;
//     while(i >= 0){
//         int c = strcmp(students[i].name,name);
//         if(c == 0){
//             printf("Name %s exists, do not insert\n",name);
//             return;
//         }
//         else if(c > 0){
//             students[i+1] = students[i];
//             i--;
//         }
//         else break;
//     }
//     i++;
//     strcpy(students[i].name,name);
//     strcpy(students[i].email,email);
//     n++;
// }

void insert(char *name, char *email){
    if (n<=0){
        strcpy(students[0].name,name);
        strcpy(students[0].email,email);
    }
    else{
        for(int k = 0; k < n; k++){
            if(strcmp(students[k].name,name) == 0){
                printf("Name %s exists, do not insert\n",name);
                return;
            }
        }
        int i = n-1;
        while(i >= 0){
            int c = strcmp(students[i].name,name);
            if(c > 0){
                students[i+1] = students[i];
                i--;
            }
            else break;
        }
        strcpy(students[i+1].name,name);
        strcpy(students[i+1].email,email);
    }
    n++;
}

void removeStudent(int idx){
    for(int i = idx; i < n-1; i++) students[i] = students[i+1];
    n--;
}

void load(char* filename){
    FILE* f = fopen(filename,"r");
    if(f == NULL) printf("Can not open file!\n");
    n = 0;
    while(!feof(f)){
        char name[256], email[256];
        fscanf(f,"%s %s",name,email);
        insert(name,email);
    }
    fclose(f);
}

void printList(){
    for(int i = 0; i < n; i++) printf("Student[%d]: %s, %s\n",i+1,students[i].name, students[i].email);
}

int binarySearch(int L, int R, char* name){
    if(L > R) return -1;
    if(L == R){
        if(strcmp(students[L].name,name)==0) return L;
        else return -1;
    }
    int m = (L+R)/2;
    int c = strcmp(students[m].name,name);
    if(c == 0) return m;
    if(c < 0) return binarySearch(m+1,R,name);
    return binarySearch(L,m-1,name);
}

void processFind(){
    char name[256];
    scanf("%s",name);
    int idx = binarySearch(0,n-1,name);
    if(idx == -1){
        printf("Not found student %s\n",name);
    }
    else{
        printf("Found student %s, at position %d, email %s\n",students[idx].name,idx,students[idx].email);
    }
}

void processLoad(){
    char filename[256];
    scanf("%s",filename);
    load(filename);
}

void processStore(){
    char filename[256];
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    for(int i = 0; i < n; i++){
        fprintf(f,"%s %s",students[i].name,students[i].email);
        if(i < n-1) fprintf(f,"\n");
    }
    fclose(f);
}

void processInsert(){
    char name[256], email[256];
    scanf("%s %s",name,email);
    insert(name,email);
}

void processRemove(){
    char name[256];
    scanf("%s",name);
    int idx = binarySearch(0,n-1,name);
    if(idx == -1) printf("Not found %s\n",name);
    else{
        removeStudent(idx);
    }
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
            run = 0; break;
            default:
            printf("Try Again!"); break;
        }
    }
}