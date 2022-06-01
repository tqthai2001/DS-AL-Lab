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

void swap(element *a, element *b){
    element temp = *a;
    *a = *b;
    *b = temp;
}

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
    fclose(fout);
}

int partition(element list[], int low, int high){
    int i,j;
    char pivot[30];
    i = low;
    j = high - 1;
    strcpy(pivot,list[high].name);
    while(1){
        while (i <= j && strcmp(list[i].name,pivot) < 0) i++;
        while (j >= i && strcmp(list[j].name,pivot) > 0) j--;
        if(i>=j) break;
        swap(&list[i], &list[j]);
        i++; j--;
    }
    swap(&list[i], &list[high]);
    return i;
}

void quick_sort(element list[], int low, int high){
    if(low < high){
        int pi = partition(list, low, high);
        quick_sort(list, low, pi - 1);
        quick_sort(list, pi + 1, high);
    }
}

int main(){
    element list[100];
    char filenamein[30], filenameout[30];

    scanf("%s", filenamein);
    load(list, filenamein);

    quick_sort(list, 0, 6);

    scanf("%s", filenameout);
    print(list, filenameout);
}