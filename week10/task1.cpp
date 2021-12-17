#include <bits/stdc++.h>
using namespace std;

bool inVec(vector<int> &v, int x) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == x) return true;
    }
    return false;
}

int main() {
    fstream file;
    file.open("job.txt", ios::in);
    int n, m;
    file >> n >> m;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++) {
        int x, y;
        file >> x >> y;
        v1.push_back(x);
        v2.push_back(y);
    }
    file.close();
    vector<int> out;
    for (int i = v2.size() - 1; i >= 0; i--) {
        if (!inVec(out, v2[i])) {
            out.push_back(v2[i]);
        }
    }
    for (int i = v1.size() - 1; i >= 0; i--) {
        if (!inVec(out, v1[i])) {
            out.push_back(v1[i]);
        }
    }
    ofstream file2;
    file2.open("job.out", ios::out);
    for (int i = out.size() - 1; i >= 0; i--) {
        file2 << out[i] << " ";
    }
    file2.close();

    
    return 0;
}