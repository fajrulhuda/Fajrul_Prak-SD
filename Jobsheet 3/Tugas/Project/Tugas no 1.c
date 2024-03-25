//Created by fajrul Huda Ash Shiddiq 23343063
//Program menampilkan bilangan Fibonacci 
#include <stdio.h>
#include <stdlib.h>

int *fibonacci(int n) {
    // Mengalokasikan memori untuk menyimpan deret Fibonacci
    int *fib = (int *)malloc(n * sizeof(int));
    if (fib == NULL) {
        printf("Pengalokasian memori gagal.\n");
        exit(1);
    }

    fib[0] = 0;
    fib[1] = 1;

    // Menghitung dan menyimpan nilai Fibonacci selanjutnya
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}

int main() {
    int n;

    printf("Masukkan jumlah n untuk bilangan Fibonacci: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Masukkan nilai n yang valid (n > 0).\n");
        return 1;
    }

    int *fib = fibonacci(n);

    printf("Deret Fibonacci hingga ke-%d adalah:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan
    free(fib);

    return 0;
}
