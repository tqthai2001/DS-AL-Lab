#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int preceding(char *first, char *second){
    int c = strcmp(first, second);
    if(c < 0) return 1;
    else if(c == 0) return 0;
    else return -1;
}

int setup_nameList(char *namelist[], char *filename){
    int i = 0;
    FILE *fin = fopen(filename, "r");
    while(!feof(fin)){
        fscanf(fin, "%s\n", namelist[i]);
        i++;
    }
    fclose(fin);
    return i;
}

void printScreen(char *nameList[], int N){
    for(int i = 0; i < N; i++){
        printf("%s", nameList[i]);
        if(i < N-1) printf("\n");
    }
}

void swap(char a[], char b[]){
    char temp[255];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}

int partition(char *list[], int low, int high){
    int i,j;
    char pivot[255];
    i = low;
    j = high - 1;
    strcpy(pivot,list[high]);
    while(1){
        while (i <= j && preceding(list[i],pivot) < 0) i++;
        while (j >= i && preceding(list[j],pivot) > 0) j--;
        if(i>=j) break;
        swap(list[i], list[j]);
        i++; j--;
    }
    swap(list[i], list[high]);
    return i;
}

void quick_sort(char *list[], int low, int high){
    if(low < high){
        int pi = partition(list, low, high);
        quick_sort(list, low, pi - 1);
        quick_sort(list, pi + 1, high);
    }
}

int main(){
    char *list[100];
    char filenamein[30], filenameout[30];
    for(int i=0;i<25;i++){
        list[i]=(char*)malloc(255*sizeof(char));
    }
    scanf("%s", filenamein);
    int N = setup_nameList(list, filenamein);
    quick_sort(list, 0, N-1);
    printScreen(list, N);
}