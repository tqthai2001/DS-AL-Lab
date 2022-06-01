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

void selection_sort(element list[], int n){
    int i, j, min;
    element tmp;
    for (i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++){
            if(strcmp(list[j].name, list[min].name) < 0) min = j;
        }
        tmp = list[i];
        list[i] = list[min];
        list[min] = tmp;
    }
    // for (i = 0; i < n-1; i++){
    //     for (j = i+1; j < n; j++){
    //         if(strcmp(list[j].name, list[i].name) < 0){
    //             tmp = list[i];
    //             list[i] = list[j];
    //             list[j] = tmp;
    //         }
    //     }
    // }
}

int main(){
    element list[100];
    char filenamein[30], filenameout[30];

    scanf("%s", filenamein);
    load(list, filenamein);

    selection_sort(list, N);

    scanf("%s", filenameout);
    print(list, filenameout);
}