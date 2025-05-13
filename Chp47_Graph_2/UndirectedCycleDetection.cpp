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
        l[end].push_front(start);
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

    bool dfs(int u, vector<bool>&visited,int parent)
    {
        visited[u] = true;

        list<int>neighbours = l[u];
        bool check = false;
        for(int v : neighbours)
        {
            if(!visited[v])
                {check = dfs(v,visited,u);}
            else if(check)
                {return true;}
            else if(v != parent)
                {return true;}
        }

        return false;
    }

    bool cycle_detect()
    {
        vector<bool>visited(5,false);
        return dfs(0,visited,-1);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
   //g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);    
    g.addEdge(3,4);
    g.print();

    cout<<g.cycle_detect();
    return 0;
}