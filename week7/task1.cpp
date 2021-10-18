#include <bits/stdc++.h>
using namespace std;

int main() {

    fstream file;
    file.open("numbers.txt", ios::in);
    vector<int> vect;
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 0;
    } else {
        int num;
        while (file >> num) {
            vect.push_back(num);
        }
    }
    file.close();
    sort(vect.begin(), vect.end());
    file.open("numbers.sorted", ios::out);
    for (int i = 0; i < vect.size(); i++) {
        file << vect[i] << " ";
    }
    file.close();

    return 0;
}