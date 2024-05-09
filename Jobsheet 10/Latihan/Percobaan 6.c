#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define MaxStack 10

int Data[MAX];

void Tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSortNonRekursif() {
    struct tump {
        int Kiri;
        int Kanan;
    } Tumpukan[MaxStack];
    
    int i, j, L, R, x, ujung = 1;
    Tumpukan[1].Kiri = 0;
    Tumpukan[1].Kanan = MAX - 1;
    while (ujung != 0) {
        L = Tumpukan[ujung].Kiri;
        R = Tumpukan[ujung].Kanan;
        ujung--;
        while (R > L) {
            i = L;
            j = R;
            x = Data[(L + R) / 2];
            while (i <= j) {
                while (Data[i] < x)
                    i++;
                while (x < Data[j])
                    j--;
                if (i <= j) {
                    Tukar(&Data[i], &Data[j]);
                    i++;
                    j--;
                }
            }
            if (L < i) {
                ujung++;
                Tumpukan[ujung].Kiri = i;
                Tumpukan[ujung].Kanan = R;
            }
            R = j;
        }
    }
}

int main() {
    int i;
    int ujung = 0; // Initialize ujung
    
    printf("DATA SEBELUM TERURUT:\n");
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() % 100 + 1;
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    QuickSortNonRekursif();
    printf("\nDATA SETELAH TERURUT:\n");
    for (i = 0; i < MAX; i++) {
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    return 0;
}
