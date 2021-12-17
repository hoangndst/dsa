#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
};


void Solved(vector<vector<int>> &graph, int V) {
    vector<bool> visited(V + 1, false);
    vector<pair<vector<int>, int>> result;
    for (int i = 1; i <= V; i++) {
        int m = INT_MAX;
        int k = -1;
        for (int j = 1; j <= V; j++) {
            if (graph[i][j] < m && !visited[j] && graph[i][j] != 0) {
                m = graph[i][j];
                k = j;   
            }
        }
        if (k != -1) {
            visited[k] = true;
            visited[i] = true;
            vector<int> temp;
            temp.push_back(i);
            temp.push_back(k);
            result.push_back(make_pair(temp, m));
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first[0] << " " << result[i].first[1] << " " << result[i].second << endl;
    }
}

int main() {

    ifstream fin;
    fin.open("connection.txt", ios::in);
    int V, E;
    fin >> V >> E;
    vector<vector<int>> graph(V + 1, vector<int>(V + 1, 0));
    for (int i = 0; i < E; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    Solved(graph, V);
    return 0;
}