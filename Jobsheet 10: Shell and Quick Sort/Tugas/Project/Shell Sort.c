//Created by_Fajrul Huda Ash Shiddiq_23343063
#include <stdio.h>

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {1, 34, 45, 22, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array sebelum diurutkan: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    shellSort(arr, n);
    printf("\nArray setelah diurutkan: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}