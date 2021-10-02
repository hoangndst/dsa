#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void push_back(Node **head, int data) {
    Node *newNode = new Node(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int count_triplets(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp->next->next != NULL) {
        if (temp->data + temp->next->data + temp->next->next->data == 0) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main() {
    Node *head = NULL;
    int n;
    cin >> n;
    while (n--) {
        int data;
        cin >> data;
        push_back(&head, data);
    }
    cout << count_triplets(head);

    return 0;
}