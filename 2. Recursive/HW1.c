#include <stdio.h>
#include <string.h>
#define N 100

int n;
int x[N];
void solution(){
    int i,count=0;
    for(i = 1; i <= n; i ++){
        if(x[i]==0) count+=1;
    }
    if(count==2){
        for(i = 1; i <= n; i ++){
            printf("%d", x[i]);
        }
        printf("\n");
    }
}
int check(int v, int k){
    return 1;
}
void Try(int k){
    for(int v = 0; v <= 1; v++){
        if(check(v,k)){
            x[k] = v;
            if(k == n) solution();
            else Try(k+1);
        }
    }
}
int main(){
    n=5;
    Try(1);
}