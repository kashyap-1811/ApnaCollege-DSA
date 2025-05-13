#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
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

//create a BST
Node* insert(Node* root, int data)
{
    if(root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if(root->data > data)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    return root;
}


Node* create_BST(const vector<int>&arr, int n)
{
    Node *root = nullptr;

    for(int i=0;i<n;i++)
    {
        root = insert(root,arr[i]);
    }

    return root;
}

void inOrder(Node *root)
{
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);    
}

void print_in_range(Node *root, int start, int end)
{
    if(root == nullptr)
        return;
    
    if(root->data>=start && root->data<=end)
    {
        print_in_range(root->left,start,end);
        cout<<root->data<<" ";
        print_in_range(root->right,start,end);
    }
    else if(root->data < start)
    {
        print_in_range(root->right,start,end);
    }
    else if(root->data > end)
    {
        print_in_range(root->left,start,end);
    }
}

int main()
{
    vector<int>arr = {8,5,10,3,6,11,1,4,14};
    Node *root = create_BST(arr,arr.size());
    
    inOrder(root);
    cout<<endl;
    print_in_range(root,5,12);
    cout<<endl;
    return 0;
}