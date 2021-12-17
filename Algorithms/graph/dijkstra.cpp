#include <bits/stdc++.h>
using namespace std;

int minDistance(vector<int> dist, vector<bool> sptSet) {
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < dist.size(); i++) {
        if (sptSet[i] == false && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

vector<int> dijkstra(vector<vector<int>> graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<bool> sptSet(V, false);
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    return dist;
}