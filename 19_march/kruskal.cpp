#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, weight;
};

void heapify(vector<Edge> &edges, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compare left child
    if (left < n && edges[left].weight < edges[smallest].weight)
        smallest = left;

    // Compare right child
    if (right < n && edges[right].weight < edges[smallest].weight)
        smallest = right;

    // If smallest is not root, swap and continue heapifying
    if (smallest != i)
    {
        swap(edges[i], edges[smallest]);
        heapify(edges, n, smallest);
    }
}

// Build Min-Heap using Heapify
void buildMinHeap(vector<Edge> &edges, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(edges, n, i);
    }
}

// Extract the minimum element (root) from heap
Edge extractMin(vector<Edge> &edges, int &n)
{
    Edge minEdge = edges[0];
    swap(edges[0], edges[n - 1]);
    n--;                  // Reduce heap size
    heapify(edges, n, 0); // Reheapify
    return minEdge;
}

int find(vector<int> &parent, int u)
{
    while (parent[u] > 0)
        u = parent[u];
    return u;
}

void Union(vector<int> &parent, int u, int v)
{
    int uroot = find(parent, u);
    int vroot = find(parent, v);

    if (uroot != vroot)
        parent[uroot] = vroot;
}

void kruskal(vector<Edge> &edges, int V)
{
    int n = edges.size();

    buildMinHeap(edges, n);

    vector<int> parent(V, -1);
    vector<Edge> mst; // Store MST edges
    int minCost = 0;

    while (mst.size() < V - 1 && n > 0)
    {
        Edge e = extractMin(edges, n);

        if (find(parent, e.u) != find(parent, e.v))
        { // If no cycle
            mst.push_back(e);
            minCost += e.weight;
            Union(parent, e.u, e.v);
        }
    }

    // Print MST
    cout << "Minimum Spanning Tree edges:" << endl;
    cout << "(from,to,weight)" << endl;
    for (Edge e : mst)
    {
        cout << "(" << e.u << " , " << e.v << " , " << e.weight << ")" << endl;
    }
    cout << "Total Minimum Cost: " << minCost << endl;
}

int main()
{
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    kruskal(edges, V);
}