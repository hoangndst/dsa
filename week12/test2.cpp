#include <bits/stdc++.h>
using namespace std;

string solution(string str) {
    stack<char> s;
    char x;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
            continue;
        }
        if (s.empty()) return "INVALID";

        switch(str[i]) {
            case ')':
                x = s.top();
                s.pop();
                if (x == '{' || x ==  '[') {
                    return "INVALID";
                }
                break;
            case '}':
                x = s.top();
                s.pop();
                if (x == '(' || x == '[') {
                    return "INVALID";
                }
                break;
            case ']':
                x = s.top();
                s.pop();
                if (x == '(' || x == '{') {
                    return "INVALID";
                }
                break;
        }
    }
    if (s.empty()) {
        return "VALID";
    }
    return "INVALID";
}

int main() {

    string s; cin >> s;
    cout << solution(s) << endl;

    return 0;
}