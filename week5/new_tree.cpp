#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *fatherNode;
    Node *firstChild;
    Node *nextSibling;
    Node (int data) {
        this->data = data;
        this->fatherNode = NULL;
        this->firstChild = NULL;
        this->nextSibling = NULL;
    }

    friend class Tree;
};

class Tree {
    Node *root;
public:
    Tree () {
        this->root = NULL;
    }

    Tree (int data) {
        this->root = new Node(data);
    }

    Node *getRoot () {
        return this->root;
    }

    Node *findNode(Node *root, int father) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data == father) {
            return root;
        }
        Node *temp = findNode(root->firstChild, father);
        if (temp != NULL) {
            return temp;
        }
        temp = findNode(root->nextSibling, father);
        if (temp != NULL) {
            return temp;
        }
        return NULL;
    }

    void addNodeToSortedLinkedList(Node *root, Node *node) {
        Node *temp = root;
        while (temp->nextSibling != NULL) {
            if (temp->nextSibling->data > node->data) {
                break;
            }
            temp = temp->nextSibling;
        }
        node->nextSibling = temp->nextSibling;
        temp->nextSibling = node;
    }

    bool insert(int father, int data) {
        Node *temp = findNode(this->root, father);
        if (temp == NULL) {
            cerr << "No such father node" << endl;
            return false;
        }
        Node *newNode = new Node(data);
        newNode->fatherNode = temp;
        if (temp->firstChild == NULL) {
            temp->firstChild = newNode;
        } else {
            addNodeToSortedLinkedList(temp->firstChild, newNode);
        }
        return true;
    }

    void print_list() {
        Node *temp = this->root->firstChild->firstChild;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->nextSibling;
        }
        cout << endl;
    }

    int countLeaf(Node *node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + countLeaf(node->firstChild) + countLeaf(node->nextSibling);
    }

    int remove(int data) {
        Node *temp = findNode(this->root, data);
        if (temp == NULL) {
            cerr << "No such node" << endl;
            return -1;
        }
        if (temp->fatherNode == NULL) {
            cerr << "Root node cannot be removed" << endl;
            return -1;
        }
        return countLeaf(temp);
    }

    void preorder(Node *node) {
        cout << node->data << " ";
        if (node->firstChild != NULL) {
            preorder(node->firstChild);
        }
        if (node->nextSibling != NULL) {
            preorder(node->nextSibling);
        }
    }

    void postorder(Node *node) {
        if (node->firstChild != NULL) {
            postorder(node->firstChild);
        }
        if (node->nextSibling != NULL) {
            postorder(node->nextSibling);
        }
        cout << node->data << " ";
    }

    int countLinkedList(Node *node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + countLinkedList(node->nextSibling);
    }

    bool isBinaryTree(Node *node) {
        if (node == NULL) {
            return true;
        }
        if (countLinkedList(node->firstChild) > 2) {
            return false;
        }
        if (countLinkedList(node->nextSibling) > 2) {
            return false;
        }
        return isBinaryTree(node->firstChild) && isBinaryTree(node->nextSibling);
    }

    void inorder(Node *node) {
        if (node->firstChild != NULL) {
            inorder(node->firstChild);
        }
        cout << node->data << " ";
        if (node->nextSibling != NULL) {
            inorder(node->nextSibling);
        }
    }

    int height(Node *node) {
        if (node == NULL) {
            return 0;
        }
        int maxHeight = 0;
        while (node != NULL) {
            int h = height(node->firstChild) + 1;
            if (h > maxHeight) {
                maxHeight = h;
            }
            node = node->nextSibling;
        }
        return maxHeight;
    }

};

int main() {

    Tree tree = Tree(1);
    tree.insert(1, 2);
    tree.insert(1, 3);
    tree.insert(2, 5);
    tree.insert(2, 6);
    tree.insert(3, 7);
    tree.insert(3, 8);
    tree.insert(5, 10);
    tree.insert(5, 11);
    tree.insert(11, 12);
    tree.insert(7, 13);
    // tree.insert(13, 14);
    // cout << tree.remove(2) << endl;
    tree.preorder(tree.getRoot());
    cout << endl;
    tree.postorder(tree.getRoot());
    cout << endl;
    tree.inorder(tree.getRoot());
    cout << endl;
    cout << tree.isBinaryTree(tree.getRoot()) << endl;
    cout << tree.height(tree.getRoot()) << endl;
    // tree.print_list();
    return 0;
}
