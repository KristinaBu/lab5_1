#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
/*
void swap(int *px, int *py){
    int t;
    t=*px;
    *px=*py; *py=t;
}
int main() {
    printf("Hello, World!\n");
    int w,x = 1, y = 2, z[10];
    int *ip; // ip - указатель на int
    //printf("%d ",*ip);
    ip = &x ; // теперь ip указывает на х
    printf("%d ",*ip);
    int *r =&y;// у теперь равен 1
    w=*r+ *ip +100;

    printf("r %d ",w);
    *ip =(*ip)++; // х теперь равен 0
    printf("%d \n",x);
    //printf("%d ",*ip);
    printf("ip %d r %d\n", *ip,*r);
    swap(&x,&y);
    printf("ip %d r %d\n", *ip,*r);
    return 0;
}
*/
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
// Генерировать случайного целого числа из диапозона [lower, upper].
int iRandom(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
void sort1(int n, int *arr){
    int i,minj,j,t=0;
    for(i=0;i<=n-1;i++){
        int min=100;
        for(j=t;j<=n-1;j++){
            if(arr[j]<min){
                min=arr[j];
                minj=j;
                printf("min %d\n",min);
            }
        }swap(&arr[minj],&arr[i]);
        printf("%d\n",i);
        printDynamicArray(n, arr);
        t=t+1;
    }
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
        // целая случайная величина
        arr[i] = iRandom(1, 9);
    }
    printf("Заданный массив: ");
    printDynamicArray(n, arr);
    printf("\n");
    sort1(n,arr);
    printf("Заданный массив: ");
    printDynamicArray(n, arr);
    printf("\n");
    return EXIT_SUCCESS;
}



