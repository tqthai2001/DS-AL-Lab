#include <stdio.h>
#include <string.h>

typedef struct Address
{
    char name[30];
    char phone[15];
    char email[30];
}Address;

typedef Address element;
int N;

void load(element list[], char *filename){
    int i = 0;
    FILE *fin = fopen(filename, "r");
    while(!feof(fin)){
        fscanf(fin, "%s %s %s\n", list[i].name, list[i].phone, list[i].email);
        i++;
    }
    fclose(fin);
    N = i;
}

void print(element list[], char *filename){
    FILE *fout = fopen(filename, "w");
    for(int i = 0; i < N; i++){
        fprintf(fout, "%s %s %s", list[i].name, list[i].phone, list[i].email);
        if(i < N-1) fprintf(fout, "\n");
    }
}

void insertion_sort(element list[], int n){
    int i, j;
    element next;
    // for (i=1; i<n; i++){
    //     next = list[i];
    //     for (j = i-1; j >= 0 && strcmp(next.name,list[j].name) < 0; j--)
    //     list[j+1] = list[j];
    //     list[j+1] = next;
    // }
    for (i=1; i<n; i++){
        next = list[i];
        j = i-1;
        while(j >= 0 && strcmp(next.name,list[j].name) < 0){
            list[j+1]=list[j];
            j--;
        }
        list[j+1] = next;
    }
}

int main(){
    element list[100];
    char filenamein[30], filenameout[30];

    scanf("%s", filenamein);
    load(list, filenamein);

    insertion_sort(list, N);

    scanf("%s", filenameout);
    print(list, filenameout);
}