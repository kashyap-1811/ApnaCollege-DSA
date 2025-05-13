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
};

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.print();

    return 0;
}