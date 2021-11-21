#include <bits/stdc++.h>
using namespace std;

int minKey(vector<int> key, vector<bool> mstSet) {
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < key.size(); i++) {
        if (mstSet[i] == false && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(vector<int> parent, vector<vector<int>> graph) {
    
}