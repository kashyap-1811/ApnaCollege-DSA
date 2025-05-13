#include <bits/stdc++.h>

using namespace std;

void pushBottom(stack<char>&s, char value)
{
    if(s.empty())
    {
        s.push(value);
        return;
    }
    char temp=s.top();
    s.pop();
    pushBottom(s,value);
    s.push(temp);
}

void reverseStack(stack<char>&s)
{
    if(s.empty())
    {
        return;
    }
    char temp=s.top();
    s.pop();

    reverseStack(s);
    pushBottom(s,temp);
}

int main()
{
    stack<char>s;

    for(int i=0;i<5;i++)
    {
        char temp;
        cin>>temp;
        s.push(temp);
    }

    reverseStack(s);

    for(int i=0;i<5;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}