#include<iostream>
using namespace std;

struct sNode {
    int data;
    sNode *next;
    sNode(int d) : data(d), next(NULL) {}
};

sNode *top = NULL;
void push(int d) {
    sNode *newNode = new sNode(d);
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    sNode *temp = top;
    top = top->next;
    delete temp;
}