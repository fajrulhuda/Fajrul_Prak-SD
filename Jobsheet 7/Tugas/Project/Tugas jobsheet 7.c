// Created by_Fajrul Huda Ash Shiddiq_23343063
#include <stdio.h>
#include <stdlib.h>

// Maksimum jumlah simpul/graf
#define MAX_NODES 100

// Struktur simpul
struct Node {
    int data;
    struct Node* next;
};

// Struktur untuk antrian simpul
struct Queue {
    struct Node *front, *rear;
};

// Inisialisasi antrian kosong
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Mengecek apakah antrian kosong
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Menambah simpul ke antrian
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue))
        queue->front = newNode;
    else
        queue->rear->next = newNode;
    queue->rear = newNode;
}

// Menghapus simpul dari antrian
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

// Fungsi untuk BFS
void BFS(int graph[MAX_NODES][MAX_NODES], int vertices, int start) {
    // Array untuk menandai apakah simpul telah dikunjungi atau belum
    int visited[MAX_NODES] = {0};

    // Inisialisasi antrian
    struct Queue* queue = createQueue();

    // Tandai simpul awal sebagai telah dikunjungi dan tambahkan ke antrian
    visited[start] = 1;
    enqueue(queue, start);

    // Loop hingga antrian kosong
    while (!isEmpty(queue)) {
        // Ambil simpul dari antrian
        int current = dequeue(queue);
        printf("%d ", current);

        // Periksa semua simpul yang terhubung dengan simpul saat ini
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                // Tandai simpul yang terhubung dan tambahkan ke antrian
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    // Bebaskan memori antrian
    free(queue);
}

int main() {
    int vertices, edges, start;
    printf("Masukkan jumlah simpul: ");
    scanf("%d", &vertices);
    printf("Masukkan jumlah sisi: ");
    scanf("%d", &edges);

    // Matriks adjasensi untuk merepresentasikan graf
    int graph[MAX_NODES][MAX_NODES] = {0};

    // Baca sisi-sisi
    printf("Masukkan sisi-sisi (contoh: simpul1 simpul2): \n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Tandai bahwa simpul u dan v terhubung
        graph[u][v] = 1;
        graph[v][u] = 1; // Jika graf tidak berarah
    }

    printf("Masukkan simpul awal untuk BFS: ");
    scanf("%d", &start);

    printf("Hasil BFS traversal: ");
    BFS(graph, vertices, start);

    return 0;
}
