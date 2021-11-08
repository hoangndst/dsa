#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Graph {
private:
    int V;
    map<int, bool>  visited;
    map<int, list<int>> adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}