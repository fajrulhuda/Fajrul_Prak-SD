#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
    int data;
    struct LinkedList *next;
} node;

node *head = NULL;
node *second = NULL;
node *third = NULL;

int main() {
    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));

    if (head == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    printf("Linked list: ");
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    free(head);
    free(second);
    free(third);

    return 0;
}
