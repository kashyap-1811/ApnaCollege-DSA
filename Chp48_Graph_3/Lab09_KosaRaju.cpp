#include <bits/stdc++.h>

using namespace std;

void DFS(int src, vector<vector<int>>&edges, vector<bool>&vis, stack<int>&s)
{
    vis[src] = true;

    cout<<src+1<<" ";

    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0]-1;
        int v = edges[i][1]-1;

        if(u == src)
        {
            if(vis[v] == false)
                DFS(v, edges, vis, s);
        }
    }

    s.push(src);
}

void transpose(vector<vector<int>>&edges)
{
    for(int i=0; i<edges.size(); i++){
        swap(edges[i][0], edges[i][1]);        
    }
}

void kosaraju(vector<vector<int>>&edges, int n)
{
    vector<bool>vis(n, false);

    stack<int>s;

    DFS(0, edges, vis, s);
    cout<<endl;

    transpose(edges);
    int counter = 1;
    for(int i=0; i<n; i++)
        vis[i] = false;

    while(!s.empty())
    {
        int curr = s.top();
        s.pop();

        if(vis[curr] == false)
        {
            cout<<"SCC"<<counter<<" : ";
            DFS(curr, edges, vis, s);
            counter++;
            cout<<endl;
        }
    }
}

int main()
{
    vector<vector<int>>edges = {
        {1,2},
        {2,3},
        {3,4},
        {4,1},
        {3,5},
        {5,6},
        {6,5},
        {6,7},
        {7,8}
    };

    kosaraju(edges, 8);
    return 0;
}