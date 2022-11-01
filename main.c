#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int srav = 0, perest = 0;

void swap(int *px, int *py) {
    int t;
    t = *px;
    *px = *py;
    *py = t;
}

void printDynamicArray(int n, const int *arr) {
    for (int i = 0; i < n; i++) {
        printf(" %d", *(arr + i)); // разыменование указателя
    }
}

int iRandom(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void sort1_mintomax(int n, int *arr) {
    int i, minj, j, t = 0;
    srav = 0;
    perest = 0;
    for (i = 0; i <= n - 1; i++) {
        int min = 100;
        for (j = t; j <= n - 1; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minj = j;
                srav += 1;
            }
        }
        if (arr[minj] != arr[i]) {
            swap(&arr[minj], &arr[i]);
            perest += 1;
        }
        t = t + 1;
    }
}

void sort1_maxtomin(int n, int *arr) {
    int i, maxj, j, t = 0;
    srav = 0;
    perest = 0;
    for (i = 0; i <= n - 1; i++) {
        int max = -100;
        for (j = t; j <= n - 1; j++) {
            if (arr[j] > max) {
                max = arr[j];
                maxj = j;
                srav += 1;
            }
        }
        if (arr[maxj] != arr[i]) {
            swap(&arr[maxj], &arr[i]);
            perest += 1;
        }
        t = t + 1;
    }
}

void sort2_mintomax(int n, int *arr) {
    int k = 1;
    srav = 0;
    perest = 0;
    for (int i = 0; i <= n - 1; i++) {
        for (int j = n - 1; j >= k; j--) { //!!!!!!!!!!!!!!!!
            srav += 1;
            if (arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);//perest+=1;
            }
        }
        k = k + 1;
    }
}

void sort2_maxtomin(int n, int *arr) {
    int k = 1;
    srav = 0;
    perest = 0;
    for (int i = 0; i <= n - 1; i++) {
        for (int j = n - 1; j >= k; j--) { //!!!!!!!!!!!!!!!!
            srav += 1;
            if (arr[j - 1] < arr[j]) {
                swap(&arr[j], &arr[j - 1]);//perest+=1;
            }
        }
        k = k + 1;
    }
}

int F_perest(int n, int *arr, int *arr1) {
    for (int q = 0; q < n - 1; q++) {
        if (arr[q] != arr1[q]) {
            perest += 1;
        }
    }
    return perest;
} //просто изменения нач масс относ результата

void res(int n, int *arr) {
    //возрастание
    for (int a = 1; a < 3; a++) {
        int *arr1 = calloc(n, sizeof(int)); //first vers - copy
        memcpy(arr1, arr, n * 4);
        printf("Количество элементов: 5. Заданный массив:");
        printDynamicArray(n, arr1);
        printf(". Сортировка по возрастанию\nМетод           Результат       Сравнений       Перестановок\n");

        if (a = 1) {
            printf("сравнений (n)  ");
            sort1_mintomax(n, arr1);
            printDynamicArray(n, arr1);
            printf("      %d               %d\n", srav, perest);

            printf("сравнений (о)  ");
            sort1_mintomax(n, arr1);
            printDynamicArray(n, arr1);
            printf("      %d               %d\n", srav, 0);
        }
        if (a = 2) {
            printf("пузырек (n)    ");
            sort2_mintomax(n, arr1);
            printDynamicArray(n, arr1);
            printf("      %d               %d\n", srav, F_perest(n, arr, arr1));

            printf("пузырек (о)    ");
            sort2_mintomax(n, arr1);
            printDynamicArray(n, arr1);
            printf("      %d               %d\n", srav, 0);
        }
    }
    //убывание
    printf("\n");
    for (int b = 1; b < 3; b++) {
        int *arr1 = calloc(n, sizeof(int)); //first vers - copy
        memcpy(arr1, arr, n * 4);

        printf("Количество элементов: 5. Заданный массив:");
        printDynamicArray(n, arr1);
        printf(". Сортировка по убыванию\nМетод           Результат       Сравнений       Перестановок\n");

        if (b = 1) {
            printf("сравнений (n)  ");
            sort1_maxtomin(n, arr1);
            printDynamicArray(n, arr1);
            printf("      %d               %d\n", srav, perest);

            printf("сравнений (о)  ");
            sort1_maxtomin(n, arr1);
            printDynamicArray(n, arr1);
            printf("      %d               %d\n", srav, 0);
        }
        if (b = 2) {
            printf("пузырек (n)    ");
            sort2_maxtomin(n, arr1);
            printDynamicArray(n, arr1);
            printf("      %d               %d\n", srav, F_perest(n, arr, arr1));

            printf("пузырек (о)    ");
            sort2_maxtomin(n, arr1);
            printDynamicArray(n, arr1);
            printf("      %d               %d\n", srav, 0);
        }
    }
} //адекватный вывод

int main() {
    setlocale(LC_ALL, "Russian");
    int n = 5;
    int *arr = calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Не удается выделить память\n");
        return EXIT_FAILURE;
    }
    srand(time(0));
    rand();
    for (int i = 0; i < n; i++) {
        arr[i] = iRandom(1, 9);
    }
    res(n, arr);
    n = 50;
    int *arr50 = calloc(n, sizeof(int));
    if (arr50 == NULL) {
        printf("Не удается выделить память\n");
        return EXIT_FAILURE;
    }
    srand(time(0));
    rand();
    for (int i = 0; i < n; i++) {
        arr50[i] = iRandom(1, 9);
    }
    n = 500;
    int *arr500 = calloc(n, sizeof(int));
    if (arr500 == NULL) {
        printf("Не удается выделить память\n");
        return EXIT_FAILURE;
    }
    srand(time(0));
    rand();
    for (int i = 0; i < n; i++) {
        arr500[i] = iRandom(1, 9);
    }
    n = 5;
    int *arr1_5 = calloc(n, sizeof(int)); //first vers - copy
    memcpy(arr1_5, arr, n * 4);
    int *arr2_5 = calloc(n, sizeof(int)); //first vers - copy
    memcpy(arr2_5, arr, n * 4);
    n = 50;
    int *arr1_50 = calloc(n, sizeof(int)); //first vers - copy
    memcpy(arr1_50, arr50, n * 4);
    int *arr2_50 = calloc(n, sizeof(int)); //first vers - copy
    memcpy(arr2_50, arr50, n * 4);
    n = 500;
    int *arr1_500 = calloc(n, sizeof(int)); //first vers - copy
    memcpy(arr1_500, arr500, n * 4);
    int *arr2_500 = calloc(n, sizeof(int)); //first vers - copy
    memcpy(arr2_500, arr500, n * 4);
    printf("\n");
    printf("Метод: сравнений (n). Сортировка по возрастанию\nN               Сравнений       Перестановок\n");
    sort1_mintomax(5, arr);
    printf("5               %d              %d\n", srav, perest);
    sort1_mintomax(50, arr50);
    printf("50              %d            %d\n", srav, perest);
    sort1_mintomax(500, arr500);
    printf("500             %d          %d\n", srav, perest);
    printf("\n");
    printf("Метод: пузырек (n). Сортировка по возрастанию\nN               Сравнений       Перестановок\n");
    sort2_mintomax(5, arr1_5);
    printf("5               %d              %d\n", srav, F_perest(5, arr2_5, arr1_5));
    sort2_mintomax(50, arr1_50);
    printf("50              %d            %d\n", srav, F_perest(50, arr2_50, arr1_50));
    sort2_mintomax(500, arr1_500);
    printf("500             %d          %d\n", srav, F_perest(500, arr2_500, arr1_500));

    free(arr);
    free(arr50);free(arr500);free(arr1_50);free(arr1_5);free(arr1_500);
    free(arr2_5);free(arr2_50);free(arr2_500);
    return EXIT_SUCCESS;
}

