#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val=0 ,Node *ptr=nullptr)
    {
        data=val;
        next=ptr;
    }

    void change_next(Node *ptr)
    {
        next=ptr;
    }

    Node* print()
    {
        cout<<data<<"->";
        return next;
    }

    Node* get_next()
    {
        return next;
    }

    // ~Node()
    // {
    //     cout<<"~Node()"<<data<<endl;
    //     if(next!=nullptr)
    //     {
    //         delete next;
    //         next=nullptr;
    //     }
    // }

    int getdata()
    {
        return data;
    }
};

class List
{
    public:
    Node* head;
    Node* tail;
    List()
    {
        head=tail=nullptr;
    }

    void push_front(int val)
    {
        Node *new_node= new Node(val,head);

        if(head==nullptr)
            head=tail=new_node;
        else
            head=new_node;
    }

    void push_back(int val)
    {
        Node* new_node= new Node(val);
        if(head==nullptr)
        {
            head=tail=new_node;
        }
        else
       {
            tail->change_next(new_node);
            tail=new_node;
        }
    }

    void print()
    {
        Node* temp=head;

        while(temp!=nullptr)
        {
           temp= temp->print();
        }
        cout<<"NULL\n";
    }

    void insert(int val,int pos)
    {
        if(pos==1||pos==0)
        {
            push_front(val);
        }
        else
        {
            Node* temp=head;
            
            for(int i=1; i<pos-1;i++)
            {
                temp=temp->next;
                if(i<pos-1 && temp == nullptr)
                {
                    cout<<"Invalid position";
                    return;
                }
            }
            
            Node *new_node = new Node(val);
            new_node->next=temp->next;
            temp->next=new_node;
        }
    }

    void pop_front()
    {
        if(head==nullptr)
        {
            cout<<"List is Empty"<<endl;
        }
        Node* temp=head;
        head=head->get_next();
        temp->change_next(nullptr);
        delete temp;
    }

    void pop_back()
    {
        Node *temp=head;

        while(temp->next->next!=nullptr)
        {
            temp=temp->get_next();
        }
        tail=temp;
        Node *prev = temp->next;
        temp->next=NULL;
        delete prev;
    }

    int searchItr(int val)
    {
        Node *temp=head;
        int pos=0;

        while(temp->get_next()!=nullptr)
        {
            if(temp->getdata()==val)
            {
                return pos;
            }
            else{
                temp=temp->get_next();
                pos++;
            }
        }
        return -1;
    }

    int helper(Node *temp, int key)
    {
        if(temp==nullptr)
            return -1;

        if(temp->getdata()==key)
        {
            return 0;
        }

        int idx = helper(temp->get_next(),key);

        if(idx==-1)
            return -1;
        else
            return idx+1;
    }

    int recursiveSearchItr(int key)
    {
        return helper(head,key);
    }

    // ~List()
    // { 
    //     if(head!=nullptr)
    //     {
    //         delete head;
    //         head=nullptr;
    //     }
    // }

    void reverseList()
    {
        Node *prev=nullptr;
        Node *curr=head;
        Node *after;
        tail=head;

        while(curr!=nullptr)
        {
            after=curr->get_next();
            curr->change_next(prev);
            prev=curr;
            curr=after;
        }
           head=prev;
    }   

    void delete_Nth_Node_from_behind(int n)
    {
        if(n==0)
        {
            pop_back();
            return;
        }
        Node *temp=head, *next_node=nullptr;

        int total=0;

        while(temp->next!=nullptr)
        {
            temp=temp->get_next();
            total++;
        }

        if(n>total+1)
        {
            cout<<"Not valid position: ";
            return;
        }
        if(n==total+1)
        {
            pop_front();
            return;
        }
        temp=head;
        for(int i=0;i<total-n;i++)
        {
            temp=temp->get_next();
        }
        Node *prev=temp->next;
        temp->next=temp->next->next;
        prev->next=nullptr;
        delete prev;
    }
};

int main()
{
    List ll;

    ll.push_front(9);
    ll.push_back(0);
    ll.push_front(8);
    ll.push_back(3);
    ll.push_back(99);
    ll.push_front(100);

    ll.insert(5,0);
    //ll.insert(11,9);
    ll.insert(44,8);
    ll.insert(55,9);

    // ll.pop_back();
    // ll.pop_front();

    // cout<<"Search for 0: "<<ll.searchItr(0)<<endl;
    // cout<<"Recursive Search 0: "<<ll.recursiveSearchItr(0)<<endl;

    // ll.print();cout<<endl;

    // ll.reverseList();
     ll.print();cout<<endl;

ll.delete_Nth_Node_from_behind(9);
     ll.delete_Nth_Node_from_behind(0);
    ll.delete_Nth_Node_from_behind(3);
    ll.print();cout<<endl;
    return 0;
}