#include <bits/stdc++.h>
using namespace std;

vector<int> v = {1, 2, 5, 10, 20, 50, 100, 200, 500};

vector<int> atm(int m) {
    vector<int> res(v.size(), 0);
    int i = 0;
    for (i = v.size() - 1; i >= 0; i--) {
        res[i] = m / v[i];
        m -= res[i] * v[i];
    }
    return res;
}

vector<int> atm2(vector<int> V, int m) {
    vector<int> res(v.size(), 0);
    int i = 0;
    for (i = v.size() - 1; i >= 0; i--) {
        res[i] = min(m / v[i], V[i]);
        m -= res[i] * v[i];
    }
    return res;
}