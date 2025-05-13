//Directed Acyclic Grpah
// Linear Order of vertices such that for every u->v
//      u comes before v in sequence
#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    Graph operator=(const Graph &g)
    {
        this->V = g.V;
        l = new list<int>[V];

        for(int i=0;i<V;i++)
        {
            l[i] = g.l[i];
        }

        return *this;
    }

    Graph(const Graph &g)
    {
        this->V = g.V;
        l = new list<int>[V];

        for(int i=0;i<V;i++)
        {
            l[i] = g.l[i];
        }
    }

    void addEdge(int start, int end){
        l[start].push_back(end);
    }

    void DFS(int src, vector<bool>&vis, stack<int>&s, vector<bool>&rec)
    {
        vis[src] = true;
        rec[src] = true;

        for(auto v : l[src])
        {
            if(rec[v] == true)
            {
                cout<<"Cycle exists error!";
                exit(0);
            }
            if(!vis[v])
                DFS(v,vis,s, rec);
        }

        s.push(src);
        rec[src] = false;
    }

    void topologicalSort()
    {
        vector<bool>vis(V,false);
        vector<bool>rec(V, false);
        stack<int>s;

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                DFS(i,vis,s,rec);
        }

        while(s.size())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);

    g.topologicalSort();
    return 0;
    }