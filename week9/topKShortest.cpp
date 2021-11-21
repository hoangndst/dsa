#include <bits/stdc++.h>
using namespace std;

struct sList {
    vector<int> dist;
    vector<vector<int>> list;
    vector<bool> visited;

    sList(int n) {
        dist.resize(n);
        list.resize(n);
        visited.resize(n);
    }
};

int V = 9;

map<int, vector<vector<int>>> listOfEdges;

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

void printPath(vector<int> list, int j) {
    if (list[j] == -1)
        return;
    printPath(list, list[j]);
    cout << j << " ";
}

void printSolution(vector<int> dist, vector<int> list, int src) {
    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; i++) {   
        cout << i << "\t\t" << dist[i] << "\t\t";
        cout << src << " ";
        printPath(list, i);
        cout << endl;
    }
}

void updateList(vector<vector<int>> &list, int index, int value) {

}

void dijkstra(vector<vector<int>> graph, int src) {
    vector<int> dist(V);
    bool sptSet[V];

    vector<int> list(V);
    
    list[src] = -1;
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (sptSet[v] != true && graph[u][v] != 0 && dist[u] != INT_MAX) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    list[v] = u;
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    printSolution(dist, list, src);
}

int main() {
    vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                {0, 0, 4, 0, 10, 0, 2, 0, 0},
                                {0, 0, 0, 14, 0, 2, 0, 1, 6},
                                {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                {0, 0, 2, 0, 0, 0, 6, 7, 0}
                    };
    int src; cin >> src;
    dijkstra(graph, src);
    

    return 0;
}