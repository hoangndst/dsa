#include <bits/stdc++.h>
using namespace std;

int count(int n) {
    int cnt = 0;
    while (n) {
        cnt = cnt + (n % 10);
        n = n / 10;
    }
    return cnt;
}

int myCompare(int x, int y) {
    int xcnt = count(x);
    int ycnt = count(y);
    if (xcnt < ycnt) {
        return 1;
    } else if (xcnt > ycnt) {
        return 0;
    } else if (xcnt == ycnt) {
        if (x < y) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, myCompare);
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    
    
    return 0;
}