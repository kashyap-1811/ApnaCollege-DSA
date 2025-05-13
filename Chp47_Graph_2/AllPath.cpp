#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int>*l;
    
    public:
    explicit Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    Graph(const Graph &g)
    {
        this->V = g.V;
        l = new list<int>[V];

        for(int i=0; i<V; i++)
            this->l[i] = g.l[i];
    }

    Graph& operator= (const Graph &g)
    {
        this->V = g.V;

        if(l != nullptr)
            delete []l;

        l = new list<int>[V];
        for(int i=0; i<V; i++)
            this->l[i] = g.l[i];

        return *this;
    }

    void addEdge(int start, int end)
    {
        l[start].push_back(end);
    }

    void DFS_helper(int start, int end, vector<bool>&vis, vector<vector<int>>&path, vector<int>&temp)
    {
        vis[start] = true;
        temp.push_back(start);

        if(start == end)
        {
            path.push_back(temp);
            temp.pop_back();
            return;
        }

        list<int>neighbours = l[start];

        for(int v : neighbours)
        {
            if(!vis[v])
            {
                DFS_helper(v, end, vis, path, temp);
                vis[v] = false;
            }
        }

        temp.pop_back();
    }

    vector<vector<int>> Allpath(int start, int end)
    {
        vector<bool>vis(V, false);
        vector<vector<int>>path;
        vector<int>temp;

        DFS_helper(start, end, vis, path, temp);

        return path;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(5, 4);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 0);

    vector<vector<int>>ans = g.Allpath(5, 1);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<"->";
        }

        cout<<endl;
    }
    return 0;
}