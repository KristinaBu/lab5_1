#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int srav=0,perest=0;
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
    srav=0; perest=0;
    for(i=0;i<=n-1;i++){
        int min=100;
        for(j=t;j<=n-1;j++){
            if(arr[j]<min){
                min=arr[j];
                minj=j;
            }
        }if(arr[minj]!=arr[i]){
            swap(&arr[minj],&arr[i]);srav+=1;
        }t=t+1;
    }
}
void sort1_maxtomin(int n, int *arr){
    int i,maxj,j,t=0;
    srav=0; perest=0;
    for(i=0;i<=n-1;i++){
        int max=-100;
        for(j=t;j<=n-1;j++){
            if(arr[j]>max){
                max=arr[j];
                maxj=j;
            }
        }if(arr[maxj]!=arr[i]){
            swap(&arr[maxj],&arr[i]);srav+=1;
        }
        t=t+1;
    }
}

void sort2_mintomax(int n, int *arr){
    int k=1;
    srav=0; perest=0;
    for(int i=0;i<=n-1;i++){
        for(int j=n-1;j>=k;j--){ //!!!!!!!!!!!!!!!!
            if(arr[j]<arr[j-1]){
                swap(&arr[j],&arr[j-1]);srav+=1;
            }
        }k=k+1;
    }
}
void sort2_maxtomin(int n, int *arr){
    int k=1;
    srav=0; perest=0;
    for(int i=0;i<=n-1;i++){
        for(int j=n-1;j>=k;j--){ //!!!!!!!!!!!!!!!!
            if(arr[j-1]<arr[j]){
                swap(&arr[j],&arr[j-1]);srav+=1;
            }
        }k=k+1;
    }
}

int F_perest(int n, int *arr,int *arr1){
    for(int q=0;q<n-1;q++){
        if (arr[q]!=arr1[q]){
            perest+=1;
        }
    }return perest;
} //perestanovki
void res(int n, int *arr){
    for(int a=0;a<5;a++){
        int *arr1 = calloc(n, sizeof(int)); //first vers - copy
        memcpy(arr1,arr,n*4);
        printDynamicArray(n, arr1); printf("\n");
        if (a=1){
            sort1_mintomax(n,arr1);
            printDynamicArray(n, arr1);
            printf("srav1 %d\n",srav);
            printf("per %d\n",F_perest(n,arr,arr1));
        }if (a=2){
            sort1_maxtomin(n,arr1);
            printDynamicArray(n, arr1);
            printf("srav2 %d\n",srav); printf("per %d\n",F_perest(n,arr,arr1));
        }if (a=3){
            sort2_mintomax(n,arr1);
            printDynamicArray(n, arr1);
            printf("srav3 %d\n",srav); printf("per %d\n",F_perest(n,arr,arr1));
        }if (a=4){
            sort2_maxtomin(n,arr1);
            printDynamicArray(n, arr1);
            printf("srav4 %d\n",srav); printf("per %d\n",F_perest(n,arr,arr1));
        }
    }
} //адекватный вывод

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
    }
    res(n,arr);
    return EXIT_SUCCESS;
}
/* Безумный вывод :(
 *
 * 
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


