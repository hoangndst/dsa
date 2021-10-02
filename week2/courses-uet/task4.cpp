#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int size;
    int front;
    int rear;
    unsigned capacity;
public:
    Queue(int k) {
        capacity = k;
        arr = new int[k];
        front = 0;
        rear = capacity - 1;
        size = 0;
    }
    ~Queue() {
        delete[] arr;
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
    bool enQueue(int data) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << arr[i] << endl;
    }
};

int main() {
    int n; cin >> n;
    Queue queue(n);
    while (n--) {
        string option; cin >> option;
        int data;
        if (option == "enqueue") {
            cin >> data;
            if (!queue.enQueue(data)) {
                cerr << "Queue is full" << endl;
            }
        } else if (option == "dequeue") {
            if (!queue.deQueue()) {
                cerr << "Queue is empty" << endl;
            }
        }
    }
    queue.print();

    return 0;
}