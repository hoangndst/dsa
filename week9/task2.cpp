#include <bits/stdc++.h>
using namespace std;

int V;

int minDistance(vector<int> dist, bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

vector<int> dijkstra(vector<vector<int>> graph, int src) {
    vector<int> dist(V, INT_MAX);
    bool sptSet[V] = {false};
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (sptSet[v] != true && graph[u][v] != 0 && dist[u] != INT_MAX) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    return dist;
}

int main() {

    int n, m; // n - number of vertices, m - number of edges
    int X, Y; // X - start vertex, Y - end vertex
    cin >> n >> m;
    cin >> X >> Y;
    V = n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x - 1][y - 1] = 1;
        graph[y - 1][x - 1] = 1;
    }
    vector<int> dist = dijkstra(graph, X - 1);
    cout << "The shortest path from "<< X << " to " <<  Y  << ": "<< dist[Y - 1] << endl;
    return 0;
}