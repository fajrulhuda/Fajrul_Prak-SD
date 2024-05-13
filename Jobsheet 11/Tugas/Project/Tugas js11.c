//Create by_Fajrul Huda Ash Shiddiq_23343063
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Mahasiswa {
    int NIM;
    char Nama[50];
    char TTL[50];
    float IPK;
};

// Fungsi pencarian sequential search
int sequentialSearch(struct Mahasiswa data[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (data[i].NIM == key) {
            return i; // Return index jika data ditemukan
        }
    }
    return -1; // Return -1 jika data tidak ditemukan
}

// Fungsi pencarian binary search
int binarySearch(struct Mahasiswa data[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (data[mid].NIM == key) {
            return mid; // Return index jika data ditemukan
        } else if (data[mid].NIM < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 jika data tidak ditemukan
}

void sortMahasiswa(struct Mahasiswa data[], int n) {
    struct Mahasiswa sorted[MAX_STUDENTS]; // Declare sorted array
    memcpy(sorted, data, n * sizeof(struct Mahasiswa)); // Copy data to a temporary array for sorting
    
    // Sorting based on NIM
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted[j].NIM > sorted[j + 1].NIM) {
                struct Mahasiswa temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Mahasiswa data[MAX_STUDENTS];
    int n, i, key;

    printf("Masukkan jumlah data mahasiswa: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character left in the input buffer

    printf("\nMasukkan data mahasiswa:");
    for (i = 0; i < n; i++) {
        printf("\nData ke-%d:\n", i+1);
        printf("NIM: ");
        scanf("%d", &data[i].NIM);
        getchar(); // Consume the newline character left in the input buffer
        printf("Nama: ");
        fgets(data[i].Nama, sizeof(data[i].Nama), stdin);
        data[i].Nama[strcspn(data[i].Nama, "\n")] = '\0'; // Remove trailing newline
        printf("TTL: ");
        fgets(data[i].TTL, sizeof(data[i].TTL), stdin);
        data[i].TTL[strcspn(data[i].TTL, "\n")] = '\0'; // Remove trailing newline
        printf("IPK: ");
        scanf("%f", &data[i].IPK);
    }

    printf("\nMasukkan NIM yang ingin dicari: ");
    scanf("%d", &key);

    // Sequential search
    int seqResult = sequentialSearch(data, n, key);
    if (seqResult != -1) {
        printf("\nSequential Search: Data ditemukan pada index %d\n", seqResult);
        printf("NIM: %d\n", data[seqResult].NIM);
        printf("Nama: %s\n", data[seqResult].Nama);
        printf("TTL: %s\n", data[seqResult].TTL);
        printf("IPK: %.2f\n", data[seqResult].IPK);                				        
    } else {
        printf("\nSequential Search: Data tidak ditemukan\n");
    }

    // Sort the data
    sortMahasiswa(data, n);

    // Binary search
    int binResult = binarySearch(data, 0, n - 1, key);
    if (binResult != -1) {
        printf("\nBinary Search: Data ditemukan pada index %d\n", binResult);
        printf("NIM: %d\n", data[binResult].NIM);
        printf("Nama: %s\n", data[binResult].Nama);
        printf("TTL: %s\n", data[binResult].TTL);
        printf("IPK: %.2f\n", data[binResult].IPK);                  
    } else {
        printf("\nBinary Search: Data tidak ditemukan\n");
    }

    return 0;
}