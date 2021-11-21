#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    ~Graph() {
        delete[] adj;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void greedyColoring();
};

void Graph::greedyColoring() {
    int res[V];
    res[0] = 0;
    for (int i = 1; i < V; i++) {
        res[i] = -1;
    }
}

int main() {

    Graph g(4);
    g.addEdge(0, 1);
    g.greedyColoring();

    return 0;
}