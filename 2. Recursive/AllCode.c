#include <stdio.h>
#include <string.h>
#define N 100

// --- Tao day so nhi phan ---

int n;
int x[N];
void solution(){
    for(int i = 1; i <= n; i ++){
        printf("%d", x[i]);
    }
    printf("\n");
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
    n=3;
    Try(1);
}

// --- Tao day so hoan vi ---

int n;
int x[N];
int mark[N];
void solution(){
    for(int i = 1; i <= n; i++)
        printf ("%d ", x[i]);
        printf("\n");
}
void Try(int k){
    for(int v = 1; v <= n; v++){
        if(!mark[v]){
            x[k] = v;
            mark[v] = 1;// update mark
            if(k == n) solution();
            else Try(k+1);
            mark[v] = 0 ;// recover
        }
    }
}
int main(){
    n = 3;
    memset (mark,0,sizeof(mark));
    Try(1);
}

// --- Tao day so tong tuyen tinh ---

int n,M,T;
int x[N];
void solution(){
for(int i = 1; i <= n; i ++)
    printf ("%d ", x[i]);
    printf ("\n");
}
int check(int v, int k){
    if(k == n) return T + v == M;
    return 1;
}
void Try(int k){
    for(int v = 1; v <= M-T-(n-k); v++){
        if(check(v,k)){
            x[k] = v;
            T += v;
            if(k == n) solution();
            else Try(k+1);
            T -= v;
        }
    }
}
int main(){
    n = 3; M = 5; T = 0;
    Try(1);
}

// --- Sudoku ---

int n;
int x[N][N];
void solution(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}
int check(int v, int r, int c){
    for(int i = 0; i <= r-1; i++)
        if(x[i][c] == v) return 0;
    for(int j = 0; j <= c-1; j++)
        if(x[r][j] == v) return 0;
    int I = r/3;
    int J = c/3;
    int i = r-3*I;
    int j = c-3*J;
    for( int i1 = 0; i1 <= i-1; i1++)
        for(int j1 = 0; j1 <= 2; j1++)
            if(x[3*I+i1][3*J+j1] == v) return 0;
                for(int j1 = 0; j1 <= j-1; j1++)
                    if(x[3*I+i][3*J+j1] == v) return 0;
                    return 1;
}
void TRY(int r, int c){
    for(int v = 1; v <= 9; v++){
        if(check(v,r,c)){
            x[r][c] = v;
            if(r == 8 && c == 8){
                solution();
            }
            else{
                if(c == 8) TRY(r+1,0);
                else TRY(r,c+1);
            }
        }
    }
}
void main(){
    TRY(0,0);
}