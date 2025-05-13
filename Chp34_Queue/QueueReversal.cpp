#include <bits/stdc++.h>

using namespace std;

void reverse(queue<int>&q)
{
     stack<int>s;
     while(!q.empty())
     {
        s.push(q.front());
        q.pop();
     }
     while(!s.empty())
     {
        q.push(s.top());
        s.pop();
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

    reverse(q);
    
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}