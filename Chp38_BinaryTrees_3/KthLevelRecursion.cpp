#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }

    ~Node(){
        if(left != nullptr)
            delete left;
        if(right != nullptr)
            delete right;
    }
};

static int idx = -1;

Node* buildTree(vector<int>nodes)
{
    idx++;
    if(nodes[idx] == -1)
        return nullptr;

    Node *new_node = new Node(nodes[idx]);
    new_node->left = buildTree(nodes);
    new_node->right = buildTree(nodes);

    return new_node;
}

void Kth_node(Node *root,int level,int count)
{
    if(root == nullptr)
        return;
    
    if(count == level)
    {
        cout<<root->data<<" ";
        return;
    }

     Kth_node(root->left,level,count+1);
     Kth_node(root->right,level,count+1);
}

int main()
{
    vector<int>nodes = {1,2,3,4,-1,-1,5,-1,6,-1,-1,7,-1,8,-1,-1,9,10,-1,-1,11,-1,12,13,-1,-1,14,-1,15,-1,-1};
    Node *root = buildTree(nodes);
    cout<<"Enter the level nodes to be printed: ";
    int k; cin>>k;

    Kth_node(root,k,1);
    return 0;
}