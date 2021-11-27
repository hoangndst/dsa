#include <bits/stdc++.h>
using namespace std;

int a[100] = {0};
int b[100] = {0};
int n;
int count = 0;

bool check() {
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp += a[i] * (i - 1);
    }
    if (tmp == n) return true;
    return false;
}

bool notDubplicate(int i) {
    int tmp = 0;
    bool mark = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            tmp += a[i] * 10 + (i - 1);
        }
    }
    for (int j = 0; j < count; j++) {
        if (tmp == b[j]) {
            mark = 0;
            return false;
        }
    }
    if (mark) {
        b[count] = tmp;
        count++;
        return true;
    }
}