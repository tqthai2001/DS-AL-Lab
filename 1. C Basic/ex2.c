#include <stdio.h>

int check_array(int a[], int b[], int sizea, int sizeb){
    int i;
    if (sizea != sizeb){
        return 0;
    }
    else {
        for(i=0;i<sizea;i++){
            if(a[i]!=b[i]){
                return 0;
            }
        }
        return 1;
    }
}

int main(){
    int A[100], B[100];
    int sizeA, sizeB;
    printf("Enter size of 2 arrays: ");
    scanf("%d %d", &sizeA, &sizeB);
    int i;
    printf("Enter array A: ");
    for(i=0;i<sizeA;i++){
        scanf("%d", &A[i]);
    }
    printf("Enter array B: ");
    for(i=0;i<sizeB;i++){
        scanf("%d", &B[i]);
    }
    if(check_array(A,B,sizeA,sizeB)){
        printf("Equal!\n");
    }
    else{
        printf("Not Equal!\n");
    }
}