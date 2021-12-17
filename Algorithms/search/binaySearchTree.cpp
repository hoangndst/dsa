#include <iostream>
using namespace std;

class BST {
    int data;
    BST *left;
    BST *right;
public:
    BST() {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }

    BST(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    BST* insert(BST *root, int data) {
        if (root == NULL) {
            root = new BST(data);
        } else if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }

    BST* search(BST *root, int data) {
        if (root == NULL) {
            return NULL;
        } else if (data == root->data) {
            return root;
        } else if (root->data > data) {
            return search(root->left, data);
        } else {
            return search(root->right, data);
        }
    }

    void printInOrder(BST *root) {
        if (root == NULL) {
            return;
        }
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }

};

int main() {

    BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
    b.printInOrder(root);
    return 0;
}