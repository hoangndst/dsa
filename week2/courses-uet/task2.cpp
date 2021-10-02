#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;

void insert(int pos, int data) {
    node* newNode = new node;    
    newNode->data = data;
    newNode->next = NULL;
    if (pos == 0) {
        head = newNode;
    }
    else {
        node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(int pos) {
    if (pos == 0) {
        head = head->next;
    }
    else {
        node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}

void printList() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, data, pos;
    cin >> n;
    while (n--) {
        string option; cin >> option;
        if (option == "insert") {
            cin >> pos >> data;
            insert(pos, data);
        }
        else if (option == "delete") {
            cin >> pos;
            deleteNode(pos);
        }
    }
    printList();
    return 0;
}