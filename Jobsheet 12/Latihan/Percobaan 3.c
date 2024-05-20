#include <stdio.h>
#include <stdlib.h>

/* Definisi node pohon biner */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Fungsi pembantu untuk mengalokasikan node baru dengan data yang diberikan dan pointer kiri serta kanan NULL */
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Fungsi untuk mencetak node pohon biner menurut traversal postorder */
void printPostorder(struct node* node) {
    if (node == NULL)
        return;

    // Rekur pada subtree kiri
    printPostorder(node->left);

    // Rekur pada subtree kanan
    printPostorder(node->right);

    // Deal dengan node saat ini
    printf("%d ", node->data);
}

/* Fungsi untuk mencetak node pohon biner menurut traversal inorder */
void printInorder(struct node* node) {
    if (node == NULL)
        return;

    // Rekur pada subtree kiri
    printInorder(node->left);

    // Cetak data node saat ini
    printf("%d ", node->data);

    // Rekur pada subtree kanan
    printInorder(node->right);
}

/* Fungsi untuk mencetak node pohon biner menurut traversal preorder */
void printPreorder(struct node* node) {
    if (node == NULL)
        return;

    // Cetak data node saat ini
    printf("%d ", node->data);

    // Rekur pada subtree kiri
    printPreorder(node->left);

    // Rekur pada subtree kanan
    printPreorder(node->right);
}

/* Program utama untuk menguji fungsi-fungsi di atas */
int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);

    printf("\nInorder traversal of binary tree is \n");
    printInorder(root);

    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);

    return 0;
}
