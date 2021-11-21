#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    vector<node*> children;

    node() {
        val = 0;
        children = vector<node*>();
    }
};



int main() {

    int m, n; cin >> m >> n;
    vector<vector <node*>> graph(m, vector<node*>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val; cin >> val;
            graph[i][j] = new node();
            graph[i][j]->val = val;
        }
    }

    return 0;
}