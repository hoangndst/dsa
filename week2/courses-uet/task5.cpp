#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int size;
    int top;
public:
    Stack(int size) {
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int value) {
        if (top == size - 1) {
            cerr << "Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = value;
    }
    void pop() {
        if (top == -1) {
            cerr << "Stack is empty" << endl;
            return;
        }
        top--;
    }
    void print() {
        if (top == -1) {
            cerr << "Stack is empty" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n; cin >> n;
    Stack stack(n);
    while (n--) { 
        string option; cin >> option;
        int data;
        if (option == "push") {
            cin >> data;
            stack.push(data);
        }
        else if (option == "pop") {
            stack.pop();
        }
    }
    stack.print();
    return 0;
}