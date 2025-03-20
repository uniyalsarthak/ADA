#include<bits/stdc++.h>
using namespace std;

int mindist(vector<int> &dist, vector<bool> &spcalculated)
{
    int minDist=INT_MAX;
    int minIndex=-1;
    for(int v=0;v<dist.size();v++)
    {
        if(!spcalculated[v] && dist[v]<minDist)
        {
            minDist=dist[v];
            minIndex=v;
        }
    }
    return minIndex;
}

void dijkstra(int source,vector<vector<int>> &graph)
{
    int V=graph.size();
    vector<int> dist(V,INT_MAX);
    vector<bool> spcalculated(V,false);
    dist[source]=0;
    for(int i=0;i<V-1;i++)
    {
        int u=mindist(dist,spcalculated);
        spcalculated[u]=true;
        for(int v=0;v<V;v++)
        {
            if(!spcalculated[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
            dist[v]=dist[u]+graph[u][v];
        }
    }
        //Print shortest distance
        cout<<"Vertex \t Distance from source"<<endl;
        for(int i=0;i<V;i++)
        {
            cout<<i<<"\t"<<dist[i]<<endl;
        }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    dijkstra(0,graph);
}