#include <stdio.h>

void Tower(int n, char a, char b, char c){
    if(n==1){
        printf("%c---%c\n",a,c);
    }
    else{
        Tower(n-1,a,c,b);
        Tower(1,a,b,c);
        Tower(n-1,b,a,c);
    }
}

int main(){
    char a='A',b='B',c='C';
    int n;
    printf("Enter the number of disk: ");
    scanf("%d",&n);
    Tower(n,a,b,c);
}