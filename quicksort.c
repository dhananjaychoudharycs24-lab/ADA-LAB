#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int size, int arr[]){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int N;
    printf("Enter the no of elements(N): ");
    scanf("%d", &N);

    int *arr = (int*)malloc(N * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(0));

    // Fill array once
    for(int i = 0; i < N; i++){
        arr[i] = rand() % 1000;
    }

    printf("Unsorted array (first few elements):\n");
    for(int i = 0; i < (N > 10 ? 10 : N); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start = clock();

    for(int k = 0; k < 50000; k++){
        quickSort(arr, 0, N - 1);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted array (first few elements):\n");
    for(int i = 0; i < (N > 10 ? 10 : N); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nTime taken to sort %d elements is %f seconds\n", N, time_taken);

    free(arr);
    return 0;
}