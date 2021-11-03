#include <bits/stdc++.h>
using namespace std;

int main() {

    fstream file;
    file.open("DATA.in", ios::in);
    int sum = 0;
    string n;
    while (file >> n) {
        try {
            int x = stoi(n);
            sum += x;
        } catch (exception e) {
            continue;
        }
    }
    cout << sum;
    return 0;
}