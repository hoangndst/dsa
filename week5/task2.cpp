#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

class BinaryTree {
    node *root;
    public:
        BinaryTree() {
            root = NULL;
        }
        void insert(int data) {
            node *newNode = new node;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            if (root == NULL) {
                root = newNode;
            } else {
                node *temp = root;
                while (temp != NULL) {
                    if (data < temp->data) {
                        if (temp->left == NULL) {
                            temp->left = newNode;
                            break;
                        } else {
                            temp = temp->left;
                        }
                    } else {
                        if (temp->right == NULL) {
                            temp->right = newNode;
                            break;
                        } else {
                            temp = temp->right;
                        }
                    }
                }
            }
        }
        void inorder(node *root) {
            if (root != NULL) {
                inorder(root->left);
                cout << root->data << " ";
                inorder(root->right);
            }
        }
        void preorder(node *root) {
            if (root != NULL) {
                cout << root->data << " ";
                preorder(root->left);
                preorder(root->right);
            }
        }
        void postorder(node *root) {
            if (root != NULL) {
                postorder(root->left);
                postorder(root->right);
                cout << root->data << " ";
            }
        }
        void levelorder(node *root) {
            queue<node *> q;
            q.push(root);
            while (!q.empty()) {
                node *temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }
};
