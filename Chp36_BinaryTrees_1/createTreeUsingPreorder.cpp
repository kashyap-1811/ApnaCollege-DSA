#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    explicit Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }

    ~Node()
    {
        if(left != nullptr)
            delete left;
        if(right != nullptr)
            delete right;
    }
};

static  int idx = -1;

Node* buildTree(vector<int>nodes)
{
    idx++;
    
    if(nodes[idx] == -1)
    {
        return nullptr;
    }

    Node *new_node = new Node(nodes[idx]); 
    new_node->left = buildTree(nodes);//left subtree
    new_node->right = buildTree(nodes);//right subtree

    return new_node;
}

void preOrderprintTree(Node *root)
{
    if(root == nullptr)
        return;

    cout<<root->data<<" ";         //root
    preOrderprintTree(root->left); //left
    preOrderprintTree(root->right);//right
}

void iterative_inOrder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node*> s;
    Node *temp = root;

    while (temp != nullptr || !s.empty())
    {
        // Reach the leftmost node of the current Node
        while (temp != nullptr)
        {
            s.push(temp);
            temp = temp->left;
        }

        // Current must be NULL at this point
        temp = s.top();
        s.pop();

        cout << temp->data << " "; // Visit the node

        // We have visited the node and its left subtree. Now, it's right subtree's turn
        temp = temp->right;
    }
}


void InOrderprintTree(Node *root)
{
    if(root == nullptr)
        return;
    
    InOrderprintTree(root->left); //left
    cout<<root->data<<" ";        //root
    InOrderprintTree(root->right);//right
}

void postOrderprintTree(Node *root)
{
    if(root == nullptr)
        return;
    
    postOrderprintTree(root->left);  //left
    postOrderprintTree(root->right); //right
    cout<<root->data<<" ";           //root
}

int main()
{
    vector<int>nodes ={
        1,2,4,-1,-1,5,-1,-1,3,-1,6,7,-1,-1,-1
    };

    Node *root = buildTree(nodes);
    // cout<<"print using preOrdera: ";
    // preOrderprintTree(root);
    // cout<<endl;
    
    cout<<"print using InOrder: ";
    InOrderprintTree(root);
    cout<<endl;

    cout<<"print using InOrder: ";
    iterative_inOrder(root);
    cout<<endl;
    
    // cout<<"print using postOrder: ";
    // postOrderprintTree(root);
    // cout<<endl;

    // cout<<"print using Iteration: ";
    // //IterationPrint(root);
    // cout<<endl;
    //     if(root == nullptr){
    //         cout<<"NULL";
    //         return(0);
    //     }
    // queue<Node*>q;
    // q.push(root);
    // q.push(nullptr);

    // while(!q.empty())
    // {
    //     Node *curr = q.front(); q.pop();

    //     if(curr == nullptr)
    //     {
    //         cout<<endl;
    //         if(q.empty())
    //             break;
    //         q.push(nullptr);
    //     }
    //     else
    //     {
    //         cout<<curr->data<<" ";
    //         if(curr->left != nullptr)
    //             q.push(curr->left);
    //         if(curr->right != nullptr)
    //             q.push(curr->right);
    //     }
    // }
    // cout<<endl;
    return 0;
}