#include <iostream>
using namespace std;

struct Student {
    int masach;
    string tensach;
    string tacgia;
    int lanxuatban;
    int sotrang;
    float giathanh;

    Student() {
        masach = 0;
        tensach = "";
        tacgia = "";
        lanxuatban = 0;
        sotrang = 0;
        giathanh = 0;
    }

    Student(int masach, string tensach, string tacgia, int lanxuatban, int sotrang, float giathanh) {
        this->masach = masach;
        this->tensach = tensach;
        this->tacgia = tacgia;
        this->lanxuatban = lanxuatban;
        this->sotrang = sotrang;
        this->giathanh = giathanh;
    }
};


struct Node {
    Node *pHead;
    Node *pNext;
    Student data;

    Node() {
        pHead = NULL;
        pNext = NULL;
    }

    Node(Student data) {
        this->data = data;
        pHead = NULL;
        pNext = NULL;
    }
};

// 1
void printList(Node *pHead) {
    Node *p = pHead;
    while (p != NULL) {
        cout << p->data.masach << " " << p->data.tensach << " " << p->data.tacgia << " " << p->data.lanxuatban << " "
             << p->data.sotrang << " " << p->data.giathanh << endl;
        p = p->pNext;
    }
}

// 2
Node *findNode(Node *pHead, int masach) {
    Node *p = pHead;
    while (p != NULL) {
        if (p->data.masach == masach) {
            return p;
        }
        p = p->pNext;
    }
    return NULL;
}

// 3
void insertTail(Node *&pHead, Student data) {
    Node *p = pHead;
    if (pHead == NULL) {
        pHead = new Node(data);
        pHead->pHead = pHead;
        return;
    }
    while (p->pNext != NULL) {
        if (p->data.masach == data.masach) {
            cout << "Da ton tai" << endl;
            return;
        }
        p = p->pNext;
    }
    p->pNext = new Node(data);
    p->pNext->pHead = pHead;
}
// 4
void deleteNode(Node *&pHead, int masach) {
    Node *p = pHead;
    if (pHead == NULL) {
        cout << "Danh sach rong" << endl;
        return;
    }
    if (pHead->data.masach == masach) {
        pHead = pHead->pNext;
        delete p;
        return;
    }
    while (p->pNext != NULL) {
        if (p->pNext->data.masach == masach) {
            p->pNext = p->pNext->pNext;
            delete p->pNext;
            return;
        }
        p = p->pNext;
    }
    cout << "Khong tim thay" << endl;
}

// 5
void printAuthorBook(Node *pHead, string tacgia) {
    Node *p = pHead;
    while (p != NULL) {
        if (p->data.tacgia == tacgia) {
            cout << p->data.masach << " " << p->data.tensach << " " << p->data.tacgia << " " << p->data.lanxuatban << " "
                 << p->data.sotrang << " " << p->data.giathanh << endl;
        }
        p = p->pNext;
    }
}

// 6
int coutBook(Node *pHead, int lanxuatban) {
    Node *p = pHead;
    int dem = 0;
    while (p != NULL) {
        if (p->data.lanxuatban == lanxuatban) {
            dem++;
        }
        p = p->pNext;
    }
    return dem;
}

// 7
void sortBookByCost(Node *&pHead) {
    Node *p = pHead;
    Node *q = pHead;
    while (p != NULL) {
        while (q != NULL) {
            if (p->data.giathanh > q->data.giathanh) {
                Student temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->pNext;
        }
        p = p->pNext;
        q = pHead;
    }
}

// 8 
void insertBookByCost(Node *&pHead, Student data) {
    Node *p = pHead;
    Node *q = pHead;
    while (p != NULL) {
        if (p->data.giathanh > data.giathanh) {
            break;
        }
        q = p;
        p = p->pNext;
    }
    if (p == pHead) {
        pHead = new Node(data);
        pHead->pNext = p;
        p->pHead = pHead;
        pHead->pHead = pHead;
    } else {
        q->pNext = new Node(data);
        q->pNext->pNext = p;
        q->pNext->pHead = pHead;
    }
}

// 9
void deleteBookInTail(Node *&pHead) {
    Node *p = pHead;
    Node *q = pHead;
    while (p != NULL) {
        q = p;
        p = p->pNext;
    }
    q->pNext = NULL;
    delete p;
}
// 10
void deleteList(Node *&pHead) {
    Node *p = pHead;
    while (p != NULL) {
        pHead = pHead->pNext;
        delete p;
        p = pHead;
    }
}