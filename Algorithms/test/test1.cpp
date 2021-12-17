#include <bits/stdc++.h>
using namespace std;


struct Node {
    int value;
    Node *next;
};

Node* deleteSingle(Node* head) {
    int key;
    vector<int> vect;
    Node *temp = head;
    while (temp) {
        vect.push_back(temp->value);
        temp = temp->next;
    }  
    for (int i = 0; i < vect.size(); i++) {
        if (count(vect.begin(), vect.end(), vect[i]) == 1) {
            key = vect[i];
            break;
        }
    }
    temp = head;
    while (temp->next) {
        if (temp->next->value == key) {
            temp->next = temp->next->next;
            break;
        } 
        temp = temp->next;
    }
    return head;
}

