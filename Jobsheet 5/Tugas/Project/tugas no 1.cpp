//creatd by Fajrul Huda Ash Shiddiq 23343063

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure untuk data buku
struct Buku {
    char judul[100];
    char pengarang[100];
    int tahun;
    struct Buku *next;
    struct Buku *prev;
};

// Fungsi untuk menambahkan buku 
void tambahBuku(struct Buku** head, char judul[], char pengarang[], int tahun) {
    // Membuat node baru
    struct Buku* newNode = (struct Buku*)malloc(sizeof(struct Buku));
    strcpy(newNode->judul, judul);
    strcpy(newNode->pengarang, pengarang);
    newNode->tahun = tahun;
    newNode->next = NULL;

    // Jika linked list masih kosong, maka newNode menjadi head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Menemukan akhir dari linked list
    struct Buku* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Menambahkan newNode ke akhir linked list
    last->next = newNode;
    newNode->prev = last;
}

// Fungsi untuk menghapus buku
void hapusBuku(struct Buku** head, char judul[]) {
    // Jika linked list kosong
    if (*head == NULL) {
        printf("Linked list kosong. Tidak ada buku untuk dihapus.\n");
        return;
    }

    // Jika buku yang akan dihapus adalah head
    if (strcmp((*head)->judul, judul) == 0) {
        struct Buku* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Buku dengan judul '%s' berhasil dihapus.\n", judul);
        return;
    }

    // Mencari buku yang akan dihapus
    struct Buku* current = *head;
    while (current != NULL && strcmp(current->judul, judul) != 0) {
        current = current->next;
    }

    // Jika buku ditemukan
    if (current != NULL) {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
        printf("Buku dengan judul '%s' berhasil dihapus.\n", judul);
    } else {
        printf("Buku dengan judul '%s' tidak ditemukan.\n", judul);
    }
}

// Fungsi untuk menampilkan seluruh data buku dalam linked list
void tampilkanBuku(struct Buku* head) {
    if (head == NULL) {
        printf("Linked list kosong. Tidak ada buku yang ditampilkan.\n");
        return;
    }

    printf("\nData Buku dalam Perpustakaan:\n");
    while (head != NULL) {
        printf("Judul: %s\n", head->judul);
        printf("Pengarang: %s\n", head->pengarang);
        printf("Tahun: %d\n", head->tahun);
        printf("--------------------------------\n");
        head = head->next;
    }
}

int main() {
    struct Buku* head = NULL;

    tambahBuku(&head, "Laskar Pelangi", "Andrea Hirata", 2005);
    tambahBuku(&head, "Bumi Manusia", "Pramoedya Ananta Toer", 1980);
    tambahBuku(&head, "Perjalanan Menuju Pulang", "Lala Bohang", 2020);

    tampilkanBuku(head);

    hapusBuku(&head, "Perjalanan Menuju Pulang");

    tampilkanBuku(head);

    return 0;
}
