#include <bits/stdc++.h>
using namespace std;

int myCompare(string x, string y) {
    string xy = x.append(y);
    string yx = y.append(x);
    return xy.compare(yx) > 0 ? 1 : 0;
}

int main() {
    int n; cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        arr[i] = s;
    }
    sort(arr.begin(), arr.end(), myCompare);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    return 0;
}