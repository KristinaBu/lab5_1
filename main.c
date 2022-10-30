#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void swap(int *px, int *py) {
    int t;
    t = *px;
    *px = *py;
    *py = t;
}
void printDynamicArray(int n, const int *arr) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i)); // разыменование указателя
    }
    printf("\n");
}
int iRandom(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void sort1_mintomax(int n, int *arr){
    int i,minj,j,t=0;
    for(i=0;i<=n-1;i++){
        int min=100;
        for(j=t;j<=n-1;j++){
            if(arr[j]<min){
                min=arr[j];
                minj=j;
            }
        }swap(&arr[minj],&arr[i]);
        t=t+1;
    }
}
void sort1_maxtomin(int n, int *arr){
    int i,maxj,j,t=0;
    for(i=0;i<=n-1;i++){
        int max=-100;
        for(j=t;j<=n-1;j++){
            if(arr[j]>max){
                max=arr[j];
                maxj=j;
            }
        }swap(&arr[maxj],&arr[i]);
        t=t+1;
    }
}

void sort2_mintomax(int n, int *arr){
    int k=1;
    for(int i=0;i<=n-1;i++){
        for(int j=n-1;j>=k;j--){ //!!!!!!!!!!!!!!!!
            if(arr[j]<arr[j-1]){
                swap(&arr[j],&arr[j-1]);
            }
        }k=k+1;
    }
}
void sort2_maxtomin(int n, int *arr){
    int k=1;
    for(int i=0;i<=n-1;i++){
        for(int j=n-1;j>=k;j--){ //!!!!!!!!!!!!!!!!
            if(arr[j-1]<arr[j]){
                swap(&arr[j],&arr[j-1]);
            }
        }k=k+1;
    }
}

void res(int n, int *arr){
    int *arr1 = calloc(n, sizeof(int)); //first vers - copy
    memcpy(arr1,arr,n*4);
    printDynamicArray(n, arr1);
    memcpy(arr,arr1,n*4);
    printf("Заданный массив arr: ");
    printDynamicArray(n, arr); // first vers
    sort1_mintomax(n,arr);
    printf("after sort1-1: ");
    printDynamicArray(n, arr); //after sort1-2
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n = 5;
    printf("Размер массива: %d\n", n);
    int *arr = calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Не удается выделить память\n");
        return EXIT_FAILURE;
    }srand(time(0));
    rand();
    for (int i = 0; i < n; i++) {
        arr[i] = iRandom(1, 9);
    }/*
    int *arr1 = calloc(n, sizeof(int)); //first vers - copy
    memcpy(arr1,arr,n*4);
    printDynamicArray(n, arr1);


    memcpy(arr,arr1,n*4);
    printf("Заданный массив arr: ");
    printDynamicArray(n, arr); // first vers
    sort1_mintomax(n,arr);
    printf("after sort1-1: ");
    printDynamicArray(n, arr); //after sort1-2

    memcpy(arr,arr1,n*4);
    printf("after memcpy: ");
    printDynamicArray(n, arr);
    printf("after sort1-2: ");
    sort1_maxtomin(n,arr);
    printDynamicArray(n, arr); //after sort1-2
    printf("\n");

    memcpy(arr,arr1,n*4);
    printf("after memcpy: ");
    printDynamicArray(n, arr); // first vers
    sort2_mintomax(n,arr);
    printf("after sort2-1: ");
    printDynamicArray(n, arr); //after sort1-2

    memcpy(arr,arr1,n*4);
    printf("after memcpy: ");
    printDynamicArray(n, arr); // first vers
    sort2_maxtomin(n,arr);
    printf("after sort2-1: ");
    printDynamicArray(n, arr); //after sort1-2
*/
    res(n,arr);
    return EXIT_SUCCESS;
}



