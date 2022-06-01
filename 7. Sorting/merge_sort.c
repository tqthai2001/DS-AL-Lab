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
    fclose(fout);
}

void merge(element arr[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    /* create temporary subarrays and copy data to them */
    element Left_Arr[n1], Right_Arr[n2];
    for (i = 0; i < n1; i++) Left_Arr[i] = arr[left + i];
    for (j = 0; j < n2; j++) Right_Arr[j] = arr[mid + 1 + j];
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2){
        if (strcmp(Left_Arr[i].name,Right_Arr[j].name) < 0){
            arr[k] = Left_Arr[i];
            i++;
        }
        else{
            arr[k] = Right_Arr[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = Left_Arr[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = Right_Arr[j];
        j++;
        k++;
    }
}

void merge_sort(element arr[], int left, int right){
    if (left < right){
        int mid = (left + right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    element list[100];
    char filenamein[30], filenameout[30];

    scanf("%s", filenamein);
    load(list, filenamein);

    merge_sort(list, 0, N-1);

    scanf("%s", filenameout);
    print(list, filenameout);
}