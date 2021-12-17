#include <bits/stdc++.h>
using namespace std;

vector<int> v = {1, 2, 5, 10, 20, 50};

int atm(int m) {
    vector<int> res;
    for (int i = v.size() - 1; i >= 0; i--) {
        while(m >= v[i]) {
            m -= v[i];
            res.push_back(v[i]);
        }
    }    
    return res.size();
}
int main() {

    int n; cin >> n;
    cout << atm(n);

    return 0;
}