#include <iostream>
#include <set>
#include <stack>
using namespace std;

class Node {
    int data;
    Node* fatherNode;
    Node* firstChild;

public:
    Node() {
        this->data = 0;
        this->fatherNode = NULL;
        this->firstChild = NULL;
    }
    
    Node(int data) {
        this->data = data;
        this->fatherNode = NULL;
        this->firstChild = NULL;
    }

    friend class Tree;
};

class Tree {

    Node* root;

public:
    Tree() {
        this->root = NULL;
    }

    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        Node *tmp = this->root;
        Node *newNode = new Node(data);
        if (tmp == NULL) {
            this->root = new Node(father);
            this->root->firstChild = newNode;
            return true;
        } else {
            while (tmp->firstChild != NULL) {
                if (tmp->data == data) {
                    return false;
                }
                if (tmp->data == father) {
                    newNode->fatherNode = tmp;
                }
                tmp = tmp->firstChild;
            }
            tmp->firstChild = newNode;
            return true;
        }
    }

    void printlist() {
        Node *tmp = this->root;
        while(tmp) {
            cout << tmp->data << " ";
            tmp = tmp->firstChild;
        }
        cout << endl;
    }
    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data) {
        int count = 0;
        set<Node*> nodes;
        Node *tmp = this->root;
        if (tmp == NULL) {
            return 0;
        }
        if (tmp->data == data) {
            while (tmp->firstChild != NULL) {
                count++;
                tmp = tmp->firstChild;
            }
            delete tmp;
            return count++;
        }
        while (tmp->firstChild != NULL) {
            if (nodes.find(tmp->firstChild->fatherNode) != nodes.end() || tmp->firstChild->data == data) {
                nodes.insert(tmp->firstChild);
                tmp->firstChild = tmp->firstChild->firstChild;
                count++;
            } else {
                tmp = tmp->firstChild;
            }
        }
        return count++;
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder() {
        stack<Node*> nodes;
        Node *tmp = this->root;
        if (tmp == NULL) {
            return;
        }
        nodes.push(tmp);
        cout << tmp->data << " ";
        while (tmp->firstChild != NULL) {
            if (tmp->firstChild->fatherNode == nodes.top()) {
                nodes.push(tmp->firstChild);
                cout << tmp->firstChild->data << " ";
            } else if (tmp->firstChild->firstChild == NULL) {
                nodes.pop();
            }
        }
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder();

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree();

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree();

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree();

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder();

    // Hàm trả về độ cao của cây
    int height();

    // Hàm trả về độ sâu của một Node
    int depth(int data);

    // Hàm đếm số lượng lá
    int numOfLeaves();

    // Hàm trả về Node có giá trị lớn nhất
    int findMax();

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild();
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây
    Tree tree;
    tree.insert(1, 2);
    tree.insert(1, 3);
    tree.insert(1, 4);
    tree.insert(3, 5);
    tree.insert(3, 6);
    tree.insert(3, 7);
    tree.insert(5, 8);
    tree.insert(5, 9);
    tree.printlist();
    // tree.preorder();
    cout << tree.remove(5) << endl;
    tree.printlist();
    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}
