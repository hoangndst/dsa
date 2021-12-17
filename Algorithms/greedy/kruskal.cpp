#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
    }
    int find(int x) {
        if (parent[x] == -1) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

};