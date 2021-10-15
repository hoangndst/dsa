#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector <pair<int, int>> vect;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vect.push_back(make_pair(a, b));
    }
    sort(vect.begin(), vect.end());

    int l, r;
    l = vect[0].first;
    r = vect[0].second;
    for (int i = 1; i < n; i++) {
        if (r >= vect[i].first) r = max(r, vect[i].second);
        else {
            cout << l << " " << r << "\n";
            l = vect[i].first;
            r = vect[i].second;
        }

    }
    cout << l << " " << r;

    return 0;
}