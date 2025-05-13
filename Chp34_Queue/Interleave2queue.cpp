#include <bits/stdc++.h>

using namespace std;

void interchange(queue<int>&q)
{
    queue<int>temp;
    int size = q.size();
    for(int i=0;i<size/2;i++)
    {
        temp.push(q.front());
        q.pop();
    }

    while(!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    interchange(q);
    
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}