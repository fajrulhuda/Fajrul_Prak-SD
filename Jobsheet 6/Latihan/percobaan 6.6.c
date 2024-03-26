#include <stdio.h>
#include <stdlib.h>

#define bool int

// Struktur node dari Stack
struct sNode {
    int data; // Changed from char to int to match with the push function and usage
    struct sNode* next;
};

// Fungsi Prototype
void push(struct sNode** top_ref, int new_data);
int pop(struct sNode** top_ref);
bool isEmpty(struct sNode* top);
void print(struct sNode* top);

// Function to insert an item at the bottom of stack.
void insertAtBottom(struct sNode** top_ref, int item) {
    if (isEmpty(*top_ref)) {
        push(top_ref, item);
    } else {
        int temp = pop(top_ref);
        insertAtBottom(top_ref, item);
        push(top_ref, temp);
    }
}

// Function to reverse the stack using insertAtBottom()
void reverse(struct sNode** top_ref) {
    if (!isEmpty(*top_ref)) {
        int temp = pop(top_ref);
        reverse(top_ref);
        insertAtBottom(top_ref, temp);
    }
}

// Driver Code
int main() {
    struct sNode* s = NULL;
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    printf("\nStack Awal");
    print(s);

    reverse(&s);

    printf("\nStack yang dibalikkan");
    print(s);

    return 0;
}

// Function to check if the stack is empty
bool isEmpty(struct sNode* top) {
    return (top == NULL) ? 1 : 0;
}

// Function to push an item to stack
void push(struct sNode** top_ref, int new_data) {
    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));
    if (new_node == NULL) {
        printf("Stack overflow \n");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

// Function to pop an item from stack
int pop(struct sNode** top_ref) {
    int res;
    struct sNode* top;

    if (*top_ref == NULL) {
        printf("Stack overflow \n");
        exit(0);
    } else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

// Function to print the linked list
void print(struct sNode* top) {
    printf("\n");
    while (top != NULL) {
        printf(" %d ", top->data);
        top = top->next;
    }
}
