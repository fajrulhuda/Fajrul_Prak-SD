#include <stdio.h>

int main(){
    int n;
    printf("Masukkan banyaknya bilangan: ");
    scanf("%d", &n);

    int angka[n]; // Declare an array to store the numbers

    for(int i = 0; i < n; i++){
        printf("Masukkan angka ke %d:", i + 1);
        scanf("%d", &angka[i]); // Store each input number in the array
    }

    for(int i = 0; i < n; i++){
        printf("Angka ke %d: %d\n", i + 1, angka[i]); // Print each number from the array
    }

    getchar();
    return 0;
}
