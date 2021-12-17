#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<bool> visited;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
    void DFSNonRecursive(int s);
};

Graph::Graph(int V) {
    this->V = V;
    visited.assign(V, false);
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS(int s) {
    visited[s] = true;
    cout << s << " ";
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); i++) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}

void Graph::DFSNonRecursive(int s) {
    stack<int> st;
    visited[s] = true;
    st.push(s);
    while(!st.empty()) {
        s = st.top();
        st.pop();
        cout << s << " ";
        for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
            if (visited[*i] == false) {
                visited[*i] = true;
                st.push(*i);
            }
        }
    }
}

int main() {

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFSNonRecursive(2);
    return 0;
}