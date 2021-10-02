#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> v;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << v[0] + v[4] << endl;

    return 0;
}