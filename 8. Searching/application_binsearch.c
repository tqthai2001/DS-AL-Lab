#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 1000001

int a[N];
int n,Q;
// data structure for data input generation
int cand[N];
int sz;

void initSet (int sz1){
    int tmp;
    for(int i = 1; i <= sz1; i ++) cand[i] = i;
    for(int k = 1; k <= sz1; k++){
        int i = rand()%sz1;
        int j = rand()%sz1;
        tmp = cand[i];
        cand[i] = cand[j];
        cand[j] = tmp;
    }
    sz = sz1;
}


int selectAndRemove(){
    int i = rand()%sz ;
    int x = cand[i];
    cand[i] = cand[sz-1];
    sz--;
    return x;
}

void genData (char* filename, int n, int Q){
    for(int i = 1; i <= n; i ++) cand[i] = i;
    srand(time(NULL));
    FILE* f = fopen (filename,"w");
    fprintf(f,"%d %d\n",n,Q);
    initSet(n);
    for(int i = 1; i <= n; i++){
        int x = selectAndRemove();
        fprintf(f,"%d ",x);
    }
    fclose(f);
}
// end of data input generation

void input(char* filename){
    FILE* f = fopen(filename,"r");
    fscanf(f,"%d%d\n",&n,&Q);
    for(int i = 1; i <= n; i++) fscanf(f,"%d",&a[i]);
    fclose(f);
}

void bruteForceSolve(){
    int cnt = 0;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++)
        if(a[i] + a[j] == Q) cnt++;
    }
    printf("Result = %d\n",cnt);
}

void swap(int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void heapify(int i, int n){
    int L = 2*i;
    int R = 2*i+1;
    int max = i;
    if(L <= n && a[L] > a[max]) max = L;
    if(R <= n && a[R] > a[max]) max = R;
    if(max != i){
        swap(i,max); heapify(max,n);
    }
}

void buildHeap(){
    for(int i = n/2; i >= 1; i--) heapify(i,n);
}

void heapSort(){
    buildHeap();
    for(int i = n; i > 1; i--){
        swap(1,i); heapify(1,i-1);
    }
}

int binarySearch(int L, int R, int Y){
// return 1 if Y appears in the sequence a[L,...,R]
    if(L > R) return 0;
    if(L == R) if(a[L] == Y) return 1; else return 0;
    int m = (L+R)/2;
    if(a[m] == Y) return 1;
    if(a[m] > Y) return binarySearch(L,m-1,Y);
    return binarySearch(m+1,R,Y);
}

void binarySearchSolve(){
    heapSort();
    int cnt = 0;
    for(int i = 1; i < n; i++){
        int ok = binarySearch(i+1,n,Q-a[i]);
        cnt += ok;
    }
    printf("Result = %d\n",cnt);
}

int main(){
    genData("arr-100000.txt",10000,10000);
    input("arr-100000.txt");

    clock_t start1 = clock();
    bruteForceSolve();
    clock_t end1 = clock();
    clock_t tick1 = end1 - start1;
    double time_in_second1=(double)tick1/CLOCKS_PER_SEC;
    printf("Brute Force - Time: %lf\n\n",time_in_second1);

    clock_t start2 = clock();
    binarySearchSolve();
    clock_t end2 = clock();
    clock_t tick2 = end2 - start2;
    double time_in_second2=(double)tick2/CLOCKS_PER_SEC;
    printf("BinSearch - Time: %lf\n\n",time_in_second2);
}