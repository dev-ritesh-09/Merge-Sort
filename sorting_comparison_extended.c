#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int n = 5000;
    int *arr1 = (int*)malloc(n * sizeof(int));
    int *arr2 = (int*)malloc(n * sizeof(int));
    
    // Generate random array
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 1000;
        arr2[i] = arr1[i];  // Copy for second algorithm
    }
    
    printf("Sorting %d elements...\n", n);
    
    // Test Merge Sort
    clock_t start = clock();
    mergeSort(arr1, 0, n - 1);
    clock_t end = clock();
    double merge_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Test Bubble Sort
    start = clock();
    bubbleSort(arr2, n);
    end = clock();
    double bubble_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Results
    printf("Merge Sort:  %.4f seconds\n", merge_time);
    printf("Bubble Sort: %.4f seconds\n", bubble_time);
    printf("Merge Sort is %.1fx faster\n", bubble_time / merge_time);
    
    free(arr1);
    free(arr2);
    return 0;
}

// Bubble Sort Implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Merge Sort Implementation
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Merge function
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}
