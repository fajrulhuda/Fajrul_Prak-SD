//Created by fajrul Huda Ash Shiddiq 23343063
//Program menampilkan bilangan Fibonacci
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int *primeNumbers(int n, int m, int *size) {
    // Mengalokasikan memori untuk menyimpan bilangan prima
    int *primes = (int *)malloc(m * sizeof(int));
    if (primes == NULL) {
        printf("Pengalokasian memori gagal.\n");
        exit(1);
    }

    int count = 0;
    for (int num = 2; count < n; num++) {
        if (isPrime(num)) {
            primes[count] = num;
            count++;

            // Mengecek apakah perlu menambah ukuran alokasi memori
            if (count == m) {
                m *= 2;
                primes = (int *)realloc(primes, m * sizeof(int));
                if (primes == NULL) {
                    printf("Pengalokasian memori gagal.\n");
                    exit(1);
                }
            }
        }
    }

    *size = count;

    return primes;
}

int main() {
    int n, m;

    printf("Masukkan jumlah n untuk bilangan prima: ");
    scanf("%d", &n);
    printf("Masukkan ukuran awal m: ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("Masukkan nilai n dan m yang valid (n > 0 dan m > 0).\n");
        return 1;
    }

    int size;

    int *primes = primeNumbers(n, m, &size);

    // Menampilkan bilangan prima hingga ke-n
    printf("Bilangan prima hingga ke-%d adalah:\n", n);
    for (int i = 0; i < size; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan
    free(primes);

    return 0;
}
