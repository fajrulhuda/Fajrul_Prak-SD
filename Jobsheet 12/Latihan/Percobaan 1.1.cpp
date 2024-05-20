#include <iostream>
#include <conio.h>
#include <cstdlib> // dibutuhkan untuk system("cls");
#include <iomanip>
using namespace std;

struct tree_node {
    tree_node* left;
    tree_node* right;
    string nomor;
    string nama;
    string nim;
    string email;
};

tree_node* root = NULL;

bool isEmpty() {
    return root == NULL;
}

void insert(string no, string nm, string n, string ml) {
    tree_node* t = new tree_node;
    t->nomor = no;
    t->nama = nm;
    t->nim = n;
    t->email = ml;
    t->left = NULL;
    t->right = NULL;

    if (isEmpty()) {
        root = t;
    } else {
        tree_node* curr = root;
        tree_node* parent = NULL;

        while (curr != NULL) {
            parent = curr;
            if (t->nomor < curr->nomor) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (t->nomor < parent->nomor) {
            parent->left = t;
        } else {
            parent->right = t;
        }
    }
}

void inorder(tree_node* p) {
    if (p != NULL) {
        inorder(p->left);
        cout << " |" << p->nomor << " | " << p->nama << " | " << p->nim << " | " << p->email << endl;
        inorder(p->right);
    }
}

void postorder(tree_node* p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        cout << " |" << p->nomor << " | " << p->nama << " | " << p->nim << " | " << p->email << endl;
    }
}

void preorder(tree_node* p) {
    if (p != NULL) {
        cout << " |" << p->nomor << " | " << p->nama << " | " << p->nim << " | " << p->email << endl;
        preorder(p->left);
        preorder(p->right);
    }
}

void print_preorder() {
    preorder(root);
}

void print_postorder() {
    postorder(root);
}

void print_inorder() {
    inorder(root);
}

int height(tree_node *root) {
    if (root == NULL)
        return -1;
    int u = height(root->left);
    int v = height(root->right);
    return (u > v) ? u + 1 : v + 1;
}

int main() {
    root = NULL;
    string x, tmp, t, o;
    int ch;

    while (1) {
        system("cls");
        cout << endl;
        cout << "Menu Utama Operasi Pohon Biner" << endl;
        cout << "--------------------" << endl;
        cout << "1. Insert/Tambah Data" << endl;
        cout << "2. Kunjungan In-Order" << endl;
        cout << "3. Kunjungan Pre-Order" << endl;
        cout << "4. Kunjungan Post-Order" << endl;
        cout << "5. Exit" << endl;
        cout << "Pilihan Anda : ";
        cin >> ch;
        cout << endl;

        switch (ch) {
            case 1:
                cout << "- NOMOR : ";
                cin >> x;
                cout << "- Nama : ";
                cin >> tmp;
                cout << "- NIM : ";
                cin >> t;
                cout << "- Email : ";
                cin >> o;
                insert(x, tmp, t, o);
                break;
            case 2:
                cout << endl;
                cout << "Kunjungan In-Order" << endl;
                cout << "---------------" << endl;
                cout << " --------------------------------------------------------------------------" << endl;
                cout << " |No|" << setw(10) << " NAMA " << setw(15) << "|" << setw(5) << " NIM " << setw(10) << "|" << setw(10) << "e-MAIL" << setw(10) << "|";
                cout << " \n --------------------------------------------------------------------------" << endl;
                print_inorder();
                getch();
                break;
            case 3:
                cout << " --------------------------------------------------------------------------" << endl;
                cout << " |No|" << setw(10) << " NAMA " << setw(15) << "|" << setw(5) << " NIM " << setw(10) << "|" << setw(10) << "e-MAIL" << setw(10) << "|";
                cout << " \n --------------------------------------------------------------------------" << endl;
                print_preorder();
                getch();
                break;
            case 4:
                cout << endl;
                cout << "Kunjungan Post-Order" << endl;
                cout << "---------------" << endl;
                cout << " --------------------------------------------------------------------------" << endl;
                cout << " |No|" << setw(10) << " NAMA " << setw(15) << "|" << setw(5) << " NIM " << setw(10) << "|" << setw(10) << "e-MAIL" << setw(10) << "|";
                cout << " \n --------------------------------------------------------------------------" << endl;
                print_postorder();
                getch();
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan yang Anda Masukkan salah!" << endl;
                getch();
                break;
        }
    }
}
