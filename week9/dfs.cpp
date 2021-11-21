#include <iostream>
#include <vector>
#include <list>
#include <stack>
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
    void DFSNonRecursive(int v);
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

void Graph::DFSNonRecursive(int v) {
    vector<bool> vst(V, false);
    stack<int> s;
    s.push(v);
    while(!s.empty()) {
        int temp = s.top();
        s.pop();
        if (!vst[temp]) {
            cout << temp << " ";
            vst[temp] = true;
        }
        list<int>::iterator i;
        for (i = adj[temp].begin(); i != adj[temp].end(); i++) {
            if (!vst[*i]) {
                s.push(*i);
            }
        }
    }
}

int main() {

    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.DFS(0);
    cout << endl;
    cout << "Following is Depth First Traversal\n";
    g.DFSNonRecursive(0);
 

    return 0;
}