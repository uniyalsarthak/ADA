#include<bits/stdc++.h>
using namespace std;

int findMinVertex(vector<int>& key, vector<bool>& visited, vector<vector<int>>& graph) {
    int V=graph.size();
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(vector<vector<int>>& graph) {
    int V=graph.size();
    vector<int> mstSet(V, -1); 
    vector<int> key(V, INT_MAX);
    vector<bool> visited(V, false); 
    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinVertex(key, visited,graph);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                mstSet[v] = u; // Stores the MST parent
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge \t Weight\n";
    for (int i = 1; i < V; i++)
        cout << mstSet[i] << " - " << i << "\t" << graph[i][mstSet[i]] << "\n";
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    primMST(graph);
    return 0;
}
