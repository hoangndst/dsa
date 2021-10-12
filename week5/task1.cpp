#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    vector<Node*> children;
    Node() {

    }
    Node(int data) {
        this->data = data;
    }
};

void createTree(Node** root, int m, int n) {
    vector<Node *> tmp(m + 1);
    while (n--) {
        int index, data;
        cin >> index >> data;

        if (tmp[data] == nullptr) {
            tmp[data] = new Node(data);
        }

        if (tmp[index] == nullptr) {
            tmp[index] = new Node(index);
        }

        tmp[index]->children.push_back(tmp[data]);
    }
    *root = tmp[1];
}

void printPreorder(Node* root) { // Root -> Left -> Right
    if (root == NULL) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        if (curr != NULL) {
            cout << curr->data << " ";
            vector<Node*>::iterator it = curr->children.end();
            while (it != curr->children.begin()) {
                it--;
                s.push(*it);
            }
        }
    }
    cout << endl;
}

void printPostorder(Node* root) { // Root -> Right -> Left
    if (root == NULL) return;
    vector<int> res;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        if (curr != NULL) {
            vector<Node*>::iterator it = curr->children.begin();
            while (it != curr->children.end()) {
                s.push(*it);
                it++;
            }
            res.push_back(curr->data);
        }
    }
    for (int i = res.size() - 1; i >= 0; i--) { // Left -> Right -> Root
        cout << res[i] << " ";
    }
    cout << endl;
}

bool isBinaryTree(Node* root) {
    if (root == NULL) return true;
    if (root->children.size() > 2) return false;
    if (root->children.size() == 0) return true;
    for (int i = 0; i < root->children.size(); i++) {
        if (!isBinaryTree(root->children[i])) return false;
    }
    return true;
}

void printInorder(Node* root) { // Left -> Root -> Right
    if (isBinaryTree(root)) {
        stack<Node*> s;
        Node* curr = root;
        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->children[0];
            }
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->children[1];
        }
        cout << endl;
    } else {
        cout << "Not a binary tree" << endl;
    }
}

int main() {
    int m; cin >> m;
    int n; cin >> n;
    Node* root = new Node(1);
    createTree(&root, m, n);
    printPreorder(root);
    printPostorder(root);
    printInorder(root);
    return 0;
}