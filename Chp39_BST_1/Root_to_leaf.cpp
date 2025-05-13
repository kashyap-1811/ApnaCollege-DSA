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

//create the BST
Node* insert(Node *root,int data)
{
    if(root == nullptr){
        root = new Node(data);
        return root;
    }
    else{
        if(root->data < data)
            root->right = insert(root->right,data);
        else
            root->left = insert(root->left,data);
        return root;
    }
}

Node* create_BST(const vector<int>&arr, int n)
{
    Node *root = nullptr;
    for(int i=0;i<n;i++)
        root = insert(root,arr[i]);

    return root;
}

void print(Node *root, vector<int>&path)
{
    path.push_back(root->data);
    if(root->left == root->right) //only when root->left == root->right == nullptr
    {
        for(int p : path)
            cout<<p<<" ";
        cout<<endl;
        return;
    }
    if(root->left != nullptr){
        print(root->left,path);
        path.pop_back();
    }

    if(root->right != nullptr){
        print(root->right,path);
        path.pop_back();
    }
}

void root_to_leaf(Node *root){
    if(root == nullptr)
        return;
    vector<int>path;
    print(root,path);
}

int main()
{
    vector<int>arr = {8,5,10,3,6,11,1,4,14};
    Node *root = create_BST(arr,arr.size());

    root_to_leaf(root);
    return 0;
}