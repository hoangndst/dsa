#include <iostream>
using namespace std;
string s;
string out[1000];

void printStr(int k) {
    for (int i = 0; i < k; i++) {
        cout << out[i];
    }
    cout << endl;
}

void Try(int k, int i) {
        for (int j = 0; j < s.size(); j++) {
                out[k] = s[j];
                if (k == i - 1) {
                    printStr(i);
                } else {
                    Try(k + 1, i);
                }
        }
}
int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
    for (int i = 2; i <= s.size(); i++) {
        Try(0, i);
    }
    return 0;
}