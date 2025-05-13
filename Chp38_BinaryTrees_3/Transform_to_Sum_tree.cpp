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

int transform_to_sum_tree(Node *root)
{
    if(root == nullptr)
        return 0;
    
    int left = transform_to_sum_tree(root->left);
    int right = transform_to_sum_tree(root->right);

    int data = root->data;
    root->data = left+right;

    return data+root->data;
}

void print(Node *root)
{
    if(root == nullptr)
        return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main()
{
    vector<int>nodes = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
    Node *root = buildTree(nodes);

    int sum = transform_to_sum_tree(root);

    print(root);

    //level order
    cout<<endl;
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if(curr == nullptr)
        {
            if(q.empty())
                break;
            else{
                cout<<endl;
                q.push(nullptr);
            }
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);
        }
    }
    
    return 0;
}