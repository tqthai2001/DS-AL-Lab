#include <stdio.h>
#include <string.h>
#define N 100

int n;
int x[N];
int mark[N];
void solution(){
    for(int i = 1; i <= n; i++)
        printf ("%d ", x[i]);
        printf("\n");
}
int check(int v, int k){
    for(int i=1; i<k; i++){
        if(x[i]==v) return 0;
    }
    return 1;
}
void Try(int k){
    for(int v = 1; v <= n; v++){
        if(check(v,k)){
            x[k] = v;
            if(k == n) solution();
            else Try(k+1);
        }
    }
}
int main(){
    n = 4;
    memset (mark,0,sizeof(mark));
    Try(1);
}