#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int>*l;

    public:

    // Constructor
    explicit Graph(int V)
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
};

int main()
{
    Graph g(10);

    g.addEdge(0,2);
    g.addEdge(1,6);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(3,7);
    g.addEdge(3,8);
    g.addEdge(4,6);
    g.addEdge(4,9);
    g.print();

    g.BFS();
    g.DFS();
    return 0;
}