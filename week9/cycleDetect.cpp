#include <iostream>
#include <list>
#include <limits>
#include <vector>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool isCyclicUtil(int v, vector<bool> visited, int parent);

    bool isCyclic();

};

bool Graph::isCyclicUtil(int v, vector<bool> visited, int parent) {
    visited[v] = true;
    for (auto i : adj[v]) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, v)) {
                return true;
            }
        } else if (i != parent) {
            return true;
        }
    }
    return false;
}

bool Graph::isCyclic() {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {    
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    if (g.isCyclic()) {
        cout << "Graph contains cycle";
    } else {
        cout << "Graph does not contain cycle";
    }


    return 0;
}