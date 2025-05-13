#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char>s;

    string name;
    cin>>name;

    for(int i=0;i<name.size();i++)
    {
        s.push(name[i]);
    }

    name.clear();

    while(!s.empty())
    {
        name.push_back(s.top());
        s.pop();
    }

    cout<<name;
    return 0;
}