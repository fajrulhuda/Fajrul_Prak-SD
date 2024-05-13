//Linear search
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    int tabInt[SIZE] = {24, 17, 18, 15, 22, 26, 13, 21, 16, 28};
    int ketemu;
    int cariData;
    int i;

    printf("Masukkan data yang dicari = ");
    scanf("%d", &cariData);

    i = 0;
    ketemu = 0;

    while (i < SIZE && ketemu != 1) {
        if (tabInt[i] == cariData) {
            ketemu = 1;
        } else {
            i++;
        }
    }

    if (ketemu == 1) {
        printf("Data %d terdapat pada kumpulan data\n", cariData);
    } else {
        printf("Data %d tidak terdapat pada kumpulan data\n", cariData);
    }

    return 0;
}
