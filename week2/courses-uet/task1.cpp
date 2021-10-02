#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> visited(n, 0);
    int res = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = 1;
        for (int j = 0; j < n; j++) {
            if (i != j && visited[j] == 0) {
                if (v[i] == v[j]) {
                    res++;
                }
            }
        }
    }
    cout << res; 

    return 0;
}