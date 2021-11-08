#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int gcd(int x, int y) {
    if (x == 0) {
        return y;
    }
    if (y == 0) {
        return x;
    }
    while (x != y) {
        if (x > y) {
            x -= y;
        } else {
            y -= x;
        }
    }
    return x;
}

int findLCM(vector<int> arr, int start, int end) {
    int ans = arr[start];
    for (int i = start + 1; i <= end; i++) {
        ans = (((ans * arr[i]) / gcd(ans, arr[i])));
    }
    return ans;
}

void subsetsUtils(vector<int> &a, vector<vector<int>> &ans, vector<int> &subset, int index) {
    ans.push_back(subset);
    for (int i = index; i < a.size(); i++) {
        subset.push_back(a[i]);
        subsetsUtils(a, ans, subset, i + 1);
        subset.pop_back();
    }
    return;
}

vector<vector<int>> subsets(vector<int> &a) {
    vector<vector<int>> ans;
    vector<int> subset;
    subsetsUtils(a, ans, subset, 0);
    return ans;
}

ll solution(vector<int> arr) {
    vector<vector<int>> sub = subsets(arr);
    ll ans = 0;
    for (int i = 1; i < sub.size(); i++) {
        ans += findLCM(sub[i], 0, sub[i].size() - 1);
    }
    const unsigned int M = 10007;
    return ans % M;
}

int main() {
    int n; cin >> n;
    while (n--) {
        int m; cin >> m;
        int a = 1;
        vector<int> arr(m);
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        cout << "Case " << a << ": " << solution(arr) << endl;
        a++;
    }
    return 0;
}