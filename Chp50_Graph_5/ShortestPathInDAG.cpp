#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M)
{
    vector<vector<pair<int, int>>> adj(N, vector<pair<int, int>>());
    for (auto edge : edges)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    vector<int> dist(N, INT_MAX);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (pair<int, int> v : adj[u])
        {
            if (dist[v.first] > v.second + dist[u])
            {
                dist[v.first] = v.second + dist[u];
                q.push(v.first);
            }
        }
    }

    for (int i = 0; i < N; i++)
        if (dist[i] == INT_MAX)
            dist[i] = -1;

    return dist;
}

int main(){
    
    int N=6, M=7;
    vector<vector<int>> edges=   {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};

    vector<int> ans = shortestPath(edges,N,M);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}