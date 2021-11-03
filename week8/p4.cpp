#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack <int> s;
    while (n--) {
        string option; cin >> option;
        if (option == "C") {
            s.pop();
            cout << "ok" << endl;
        } else if (option == "D") {
            int x = s.top() * 2;
            s.push(x);
            cout << "ok" << endl;
        } else if (option == "+") {
            int temp = s.top(); s.pop();
            int temp2 = s.top() + temp;
            s.push(temp);
            s.push(temp2);
            cout << "ok" << endl;
        } else {
            int x = stoi(option);
            s.push(x);
            cout << "ok" << endl;
        }
    }
    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum << endl;
    return 0;
}