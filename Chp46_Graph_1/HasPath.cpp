#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> *l; //for weighted graph--> list<pair<int,int>>*l;
    public:

    explicit Graph(int V)
    {
        this->V = V;
        this->l = new list<int>[V];
    }

    Graph(const Graph &g)
    {
        this->V = g.V;
        for(int i=0; i<V; i++)
            this->l[i] = g.l[i];
    }

    Graph operator= (const Graph &g)
    {
        this->V = g.V;
        if(l != nullptr)
            delete []l;

        for(int i=0; i<V; i++)
            this->l[i] = g.l[i];

        return *this;
    }

    void addEdge(int startNode, int endNode) //startNode ---- endNode
    {
        l[startNode].push_back(endNode);
        l[endNode].push_back(startNode);
    }

    void print()
    {
        for(int start=0;start<V;start++)
        {
            cout<<"Start Node: "<<start<<": ";
            list<int>neighbours = l[start];
            for(int V : neighbours)
                cout<<V<<" ";
            cout<<endl;
        }
    }

    bool HasPath(int start, int end, vector<bool>&visited)
    {
        if(start == end)
            return true;
            
        visited[start] = true;
        list<int>neighbours = l[start];

        bool check = false;
        for(int v : neighbours)
        {
            if(!visited[v])
                check = HasPath(v,end,visited);

            if(check == true)
                return true;
        }

        return false;
    }
};

int main()
{
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);

    //g.print();

    vector<bool>visited(7,false);
    cout<<g.HasPath(5,6,visited);
    return 0;
}