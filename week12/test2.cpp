#include <bits/stdc++.h>
using namespace std;

string solution(string str) {
    vector<char> s;
    char x;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            // s.push(str[i]);
            // continue;
            if (str[i] == '{') {
                if (find(s.begin(), s.end(), '(') != s.end() || find(s.begin(), s.end(), '[') != s.end()) {
                    return "INVALID";
                } else {
                    s.push_back(str[i]);
                }
            } else if (str[i] == '[') {
                if (find(s.begin(), s.end(), '(') != s.end()) {
                    return "INVALID";
                } else {
                    s.push_back(str[i]);
                }
            } else {
                s.push_back(str[i]);
            }
        }
        if (s.empty()) return "INVALID";

        switch(str[i]) {
            case ')':
                x = s.back();
                s.pop_back();
                if (x == '{' || x ==  '[') {
                    return "INVALID";
                }
                break;
            case '}':
                x = s.back();
                s.pop_back();
                if (x == '(' || x == '[') {
                    return "INVALID";
                }
                break;
            case ']':
                x = s.back();
                s.pop_back();
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