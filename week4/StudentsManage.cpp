#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id;
    string name;
    string Class;
    Student(int id, string name, string Class) : id(id), name(name), Class(Class) {}
};

class StudentsManage {
    private:
        list<Student> *students;
        int SIZE;
    public:
        StudentsManage(int SIZE);
        void Insert(int id, string name, string Class);
        void Delete(int id);
        void Info(int id);
        int hash(int id);
};

StudentsManage::StudentsManage(int SIZE) {
    this->SIZE = SIZE;
    students = new list<Student>[SIZE];
}

int StudentsManage::hash(int id) {
    return id % SIZE;
}

void StudentsManage::Insert(int id, string name, string Class) {
    int index = hash(id);
    students[index].push_back(Student(id, name, Class));
}

void StudentsManage::Delete(int id) {
    int index = hash(id);
    list<Student>::iterator it;
    for (it = students[index].begin(); it != students[index].end(); it++) {
        if (it->id == id) {
            students[index].erase(it);
            break;
        }
    }
}

void StudentsManage::Info(int id) {
    int index = hash(id);
    list<Student>::iterator it;
    bool flag = false;
    for (it = students[index].begin(); it != students[index].end(); it++) {
        if (it->id == id) {
            cout << it->name << "," << it->Class << endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "NA,NA" << endl;
    }
}

int main() {
    
    StudentsManage st = StudentsManage(10);
    st.Insert(1, "Tuan", "K61CS");
    st.Insert(2, "Vinh", "K43C");
    st.Info(3);
    st.Info(2);
    st.Delete(2);
    st.Info(2);

    return 0;
}






