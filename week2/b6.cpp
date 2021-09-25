#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<int> front, rear;
    int n; cin >> n;
    while (n--) {
        int option; cin >> option;
        if (option == 1) {
            int x; cin >> x;
            rear.push(x);
        }
        else {
            if (front.empty()) {
                while(!rear.empty()) {
                    front.push(rear.top());
                    rear.pop();
                }
            }
            if (!front.empty()) {
                if (option == 2) {
                    front.pop();
                }
                else {
                    cout << front.top() << endl;
                }
            }
        }

    }
    return 0;
}