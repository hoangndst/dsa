#include <iostream>
using namespace std;

struct Stack {
    int top;
    int size;
    int *array;
    Stack (int size) {
        top = -1;
        this->size = size;
        array = new int[size];
    }
    ~Stack () {
        delete[] array;
    }
    void push (int value) {
        if (top == size - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        array[++top] = value;
    }
    int pop () {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return array[top--];
    }

};
