#include <bits/stdc++.h>

using namespace std;

class Graph{
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

    void addEdge(int start, int end)
    {
        l[start].push_back(end);
        l[end].push_back(start);
    }

    void print()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<" ";
            list<int>neighbours = l[i];
            for(int v : neighbours)
                cout<<v<<" ";
            cout<<endl;
        }
    }

    bool dirCycleHelper(int src,vector<bool>&vis, vector<bool>&path)
    {
        vis[src] = true;
        path[src] = true;
        list<int>neighbours = l[src];

        for(int v : neighbours)
        {
            if(!vis[v])
            {
                if(dirCycleHelper(v,vis,path))
                    return true;
            }

            else if(path[v])
            {
                return true;
            }
        }

        path[src] = false;
        return false;
    }

    bool DirCycleDetection()
    {
        vector<bool>visited(V,false);
        vector<bool>recpath(V,false);

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
               if(dirCycleHelper(i,visited,recpath))
                    return true; 
            }
        }

        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,0);    
    g.print();

    cout<<g.DirCycleDetection();
    return 0;
}