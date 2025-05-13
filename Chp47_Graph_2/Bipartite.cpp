#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int>*l;

    public:

    // Constructor
    Graph(int V)
    {
        this->V = V;
        this->l = new list<int>[V];
    }

    // Copy Constructor
    Graph(const Graph& other)
    {
        V = other.V;
        l = new list<int>[V];
        for(int i = 0; i < V; ++i)
        {
            l[i] = other.l[i];
        }
    }

    // Copy Assignment Operator
    Graph& operator=(const Graph& other)
    {
        if (this != &other)
        {
            delete[] l;  // Free the existing memory

            V = other.V;
            l = new list<int>[V];
            for(int i = 0; i < V; ++i)
            {
                l[i] = other.l[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Graph()
    {
        delete[] l;
    }

    void addEdge(int startnode, int endnode)
    {
        l[startnode].push_back(endnode);
        l[endnode].push_back(startnode);
    }

    void print()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<": ";

            list<int>neighbours = l[i];
            for(int v : neighbours)
                cout<<v<<" ";
            cout<<endl;
        }
    }

    void BFS()
    {
        vector<int>vis(10,false);

        queue<int>q;

        for(int i=0;i<V;i++)
        {
            if(vis[i])
                continue;
            
            q.push(i);
            vis[i] = true;
            while(q.size() > 0)
            {
                int curr = q.front();
                q.pop();
                cout<<curr<<" ";

                list<int>temp = l[curr];
                for(int v : temp)
                {
                    if(!vis[v])
                    {
                       vis[v] = true;
                       q.push(v);
                    }
                }
            }
        }
        cout<<endl;
    }

    void DFS_helper(int u, vector<bool>&visited)
    {
        visited[u] = true;
        cout<<u<<" ";

        list<int>neighbours = l[u];
        for(int v : neighbours)
        {
            if(!visited[v])
            {
                DFS_helper(v,visited);
            }
        }
    }

    void DFS()
    {
        vector<bool>visited(10,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                DFS_helper(i,visited);
        }
    }

    bool isBipartite()
    {
        queue<int>q;
        vector<int>color(V,-1);
        q.push(0);
        color[0] = 0;

        while(q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            list<int>neighbours = l[curr];

            for(int v : neighbours)
            {
                if(color[v] == -1) //unvisited
                {
                    q.push(v);
                    color[v] = !color[curr];
                }
                else if(color[v] == color[curr])
                    return false;
            }
        }
        return true;
    }

    int dfs(int src, vector<bool>&vis, int parent, int count)
    {
        vis[src] = true;
        list<int>neighbours = l[src];
        for(int v : neighbours)
        {
            if(!vis[v])
            {
                int value = dfs(v,vis,src,count+1);
                return value;
            }
            else if(v != parent)
                return count;
        }

        return -1;
    }

    bool isCycle()
    {
        vector<bool>visited(V,false);
        int count = dfs(0,visited,-1,0);
        if(count == -1) //true if cycle does not exist
            return true;

        else if(count%2 == 0)//false if cycle is odd
            return false;

        else              //true is cycle is even
            return true;
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0,1);
    // g.addEdge(0,2);
    // g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.print();

    cout<<g.isBipartite()<<endl; //approach 1
    cout<<g.isCycle()<<endl; //approach 2
    return 0;
}