#include <bits/stdc++.h>
using namespace std;

void find(int arr[], int n) {
    bool a = false;
    for (int i = 0; i < n - 1; i++) {
        unordered_set<int> s;
        for (int j = i + 1; j < n; j++){
            int tmp = -(arr[i] + arr[j]);
            if (s.find(tmp) != s.end()) {
                cout << arr[i] << " " << arr[j] << " " << tmp << endl;
                a = true;
            }
            else s.insert(arr[j]);
        }
    }
    if (a == false) cout << "Not Found" << endl;
}
