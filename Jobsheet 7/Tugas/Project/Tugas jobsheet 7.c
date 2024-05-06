#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Struktur untuk node queue
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Struktur untuk queue
struct Queue {
    struct QueueNode *front, *rear;
};

// Fungsi untuk membuat node queue baru
struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk membuat queue baru
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Fungsi untuk memeriksa apakah queue kosong
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Fungsi untuk menambahkan elemen ke dalam queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Fungsi untuk mengeluarkan elemen dari queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return -1;
    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

// Fungsi untuk melakukan traversal BFS
void BFS(int adjacencyMatrix[][MAX_SIZE], int vertices, int startVertex) {
    int visited[MAX_SIZE] = {0}; // Array untuk melacak vertex yang telah dikunjungi
    struct Queue* queue = createQueue(); // Membuat queue untuk traversal BFS
    visited[startVertex] = 1; // Tandai vertex awal sebagai telah dikunjungi
    enqueue(queue, startVertex); // Tambahkan vertex awal ke dalam queue

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue); // Keluarkan sebuah vertex dari queue
        printf("%d ", currentVertex); // Cetak vertex saat ini
        for (int i = 0; i < vertices; i++) {
            // Periksa vertex-vertex yang berdekatan dengan vertex saat ini
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Tandai vertex berdekatan sebagai telah dikunjungi
                enqueue(queue, i); // Tambahkan vertex berdekatan ke dalam queue
            }
        }
    }
}

int main() {
    int vertices, edges, startVertex;
    printf("Masukkan jumlah vertex: ");
    scanf("%d", &vertices);
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];

    printf("Masukkan matriks adjacency:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Masukkan vertex awal: ");
    scanf("%d", &startVertex);

    printf("Traversal BFS dimulai dari vertex %d: ", startVertex);
    BFS(adjacencyMatrix, vertices, startVertex);
    printf("\n");

    return 0;
}