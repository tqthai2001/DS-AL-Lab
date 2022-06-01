#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i){
    int largest = i; // parents = i
    int l = 2 * i + 1; // leftChild = 2i+1
    int r = 2 * i + 2; // rightChild = 2i+2

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i){
        printf("%d\n", arr[i]);
    }
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7, 1, 9, 2, 20};
    int n = 10;
    heapSort(arr, n);
    printArray(arr, n);
}