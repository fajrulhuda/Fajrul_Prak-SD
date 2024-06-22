//creatd by Fajrul Huda Ash Shiddiq 23343063
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure untuk data mobil
struct Mobil {
    char no_plat[15];
    char merk[50];
    char nama_pemilik[100];
    struct Mobil *next;
    struct Mobil *prev;
};

// Fungsi untuk menambahkan mobil 
void tambahMobil(struct Mobil** head, char no_plat[], char merk[], char nama_pemilik[]) {
    // Membuat node baru
    struct Mobil* newNode = (struct Mobil*)malloc(sizeof(struct Mobil));
    strcpy(newNode->no_plat, no_plat);
    strcpy(newNode->merk, merk);
    strcpy(newNode->nama_pemilik, nama_pemilik);
    newNode->next = NULL;

    // Jika linked list masih kosong, maka newNode menjadi head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Menemukan akhir dari linked list
    struct Mobil* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Menambahkan newNode ke akhir linked list
    last->next = newNode;
    newNode->prev = last;
}

// Fungsi untuk menghapus mobil berdasarkan no plat
void hapusMobil(struct Mobil** head, char no_plat[]) {
    // Jika linked list kosong
    if (*head == NULL) {
        printf("Linked list kosong. Tidak ada mobil untuk dihapus.\n");
        return;
    }

    // Jika mobil yang akan dihapus adalah head
    if (strcmp((*head)->no_plat, no_plat) == 0) {
        struct Mobil* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Mobil dengan nomor plat '%s' berhasil dihapus.\n", no_plat);
        return;
    }

    // Mencari mobil yang akan dihapus
    struct Mobil* current = *head;
    while (current != NULL && strcmp(current->no_plat, no_plat) != 0) {
        current = current->next;
    }

    // Jika mobil ditemukan
    if (current != NULL) {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
        printf("Mobil dengan nomor plat '%s' berhasil dihapus.\n", no_plat);
    } else {
        printf("Mobil dengan nomor plat '%s' tidak ditemukan.\n", no_plat);
    }
}

// Fungsi untuk menampilkan seluruh data mobil dalam linked list
void tampilkanMobil(struct Mobil* head) {
    if (head == NULL) {
        printf("Linked list kosong. Tidak ada mobil yang ditampilkan.\n");
        return;
    }

    printf("\nAntrian Mobil di Perparkiran:\n");
    while (head != NULL) {
        printf("Nomor Plat: %s\n", head->no_plat);
        printf("Merk Mobil: %s\n", head->merk);
        printf("Nama Pemilik: %s\n", head->nama_pemilik);
        printf("--------------------------------\n");
        head = head->next;
    }
}

int main() {
    struct Mobil* head = NULL;

    tambahMobil(&head, "BA 1988 ABC", "Toyota Supra", "Kevin");
    tambahMobil(&head, "BA 3140 XYZ", "Koenigsegg", "Rizal");
    tambahMobil(&head, "BA 6750 QWE", "Pagani Huayra", "Anton");

    tampilkanMobil(head);

    hapusMobil(&head, "BA 3140 XYZ");

    tampilkanMobil(head);

    return 0;
}
