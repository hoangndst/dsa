#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* parent;
    Node* left;
    Node* right;

    // Các biến tạm dưới đây có thể dùng để lưu vị trí, kiểm tra nếu sinh viên thấy cần thiết
    bool tempBool1; // Hai biến tạm kiểu boolean có thể dùng cho bất kỳ mục đích gì
    bool tempBool2;
    int tempInt1; // Hai biến tạm kiểu intcó thể dùng cho bất kỳ mục đích gì
    int tempInt2;
    Node* tempNode1; // Hai biến tạm kiểu Node* có thể dùng cho bất kỳ mục đích gì
    Node* tempNode2;

    Node(int data, Node* parent, Node* left, Node* right) {
        this->data = data;
        this->parent = parent;
        this->left = left;
        this->right = right;
    }
};

string decimalToBinary(int n) {
    string result = "";
    while (n > 0) {
        result = to_string(n % 2) + result;
        n /= 2;
    }
    return result;
}

Node *push(Node *root, int n, int newValue) {
    if (root == NULL || n == 0) {
        return new Node(newValue, NULL, NULL, NULL);
    }
    string binary = decimalToBinary(n + 1);
    Node *cur = root;
    for (int i = 1; i < binary.size() - 1; i++) {
        if (binary[i] == '0') {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    if (binary[binary.size() - 1] == '0') {
        cur->left = new Node(newValue, cur, NULL, NULL);
        cur = cur->left;
    } else {
        cur->right = new Node(newValue, cur, NULL, NULL);
        cur = cur->right;    
    }
    while (cur->parent != NULL) {
        if (cur->data > cur->parent->data) {
            swap(cur->data, cur->parent->data);
            cur = cur->parent;
        } else {
            break;
        }
    }
    if (cur->parent == NULL) {
        return cur;
    } else {
        return root;
    }
}

int getMax(Node *root) {
    if (root == NULL) {
        return -1;
    }
    return root->data;
}