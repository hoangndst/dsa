#include <bits/stdc++.h>
using namespace std;
int main() {
    string str = "";
    int t; cin >> t;
    stack<string> tmp;
    while (t--) {
        int option; cin >> option;
        if (option == 1) {
            string s; cin >> s;
            tmp.push(str);
            str += s;
        }
        else if (option == 2) {
            int n; cin >> n;
            tmp.push(str);
            str.erase(str.size() - n);
        }
        else if (option == 3) {
            int n; cin >> n;
            cout << str[n - 1] << endl;
        }
        else if (option == 4) {
            str = tmp.top();
            tmp.pop();
        }

    }
    return 0;
}
