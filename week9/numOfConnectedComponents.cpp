#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
private:
    int V;
    vector<list<int>> adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v, vector<bool> &visited);
    int numOfConnectedComponents();
};


Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFS(int V, vector<bool> &visited) {
    visited[V] = true;
    list<int>::iterator i;
    for (i = adj[V].begin(); i != adj[V].end(); i++) {
        if (!visited[*i]) {
            DFS(*i, visited);
        }
    }
}

int Graph::numOfConnectedComponents() {
    vector<bool> visited(V, false);
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, visited);
            count++;
        }
    }
    return count;
}

int main() {
    
    int V, e;
    cin >> V; // number of vertices
    cin >> e; // number of edges
    Graph g(V);
    for (int i = 0; i < e; i++) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v - 1, w - 1);
    }
    cout << "Number of Connected Components is: " << g.numOfConnectedComponents() << endl;

    return 0;
}