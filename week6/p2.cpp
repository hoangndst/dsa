#include <iostream>
using namespace std;

bool pass(string source, string input) {
    int i = 0;
    int j = 0;
    while (i < source.size()) {
        if (source[i] == input[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    if (j == input.size()) {
        return true;
    } else {
        return false;
    }
}

int main() {

    string source;
    cin >> source;
    int n;
    cin >> n;
    string out = "";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (pass(source, s)) {
            if (s.size() > out.size()) {
                out = s;
            }
        }
    }

    cout << out << endl;

    return 0;
}