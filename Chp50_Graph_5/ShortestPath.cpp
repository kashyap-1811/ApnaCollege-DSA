#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M)
{
    vector<vector<int>> adj(N, vector<int>());
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> dist(N, INT_MAX);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[v] > 1 + dist[u])
            {
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
    }

    for (int i = 0; i < N; i++)
        if (dist[i] == INT_MAX)
            dist[i] = -1;

    return dist;
}

int main(){
    
    int N=9, M=10;
    vector<vector<int>> edges= {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};

    vector<int> ans = shortestPath(edges,N,M);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}