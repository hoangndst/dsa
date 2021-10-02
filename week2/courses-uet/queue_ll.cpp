#include <iostream>
using namespace std;

struct qNode {
    int data;
    qNode *next;
    qNode(int d) : data(d), next(NULL) {}
};

struct Queue {
    qNode *front;
    qNode *rear;
    Queue() : front(NULL), rear(NULL) {}
    void enqueue(int d) {
        qNode *newNode = new qNode(d);
        if (front == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    int dequeue() {
        int d = front->data;
        qNode *temp = front;
        front = front->next;
        delete temp;
        return d;
    }
};
