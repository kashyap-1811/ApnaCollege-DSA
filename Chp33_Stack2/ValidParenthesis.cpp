#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
       stack<char>sta;

       sta.push(s[0]);

       for(int i=1;i<s.size();i++)
       {
            if(sta.empty())
            {
                sta.push(s[i]);
            }
            else if(sta.top()=='(' && s.at(i)==')')
            {
                sta.pop();
            }
            else if(sta.top()=='{' && s.at(i)=='}')
            {
                sta.pop();
            }
            else if(sta.top()=='[' && s.at(i)==']')
            {
                sta.pop();
            }
            else
            {
                sta.push(s[i]);
            }
       }

       if(sta.empty())
            return true;
        else
            return false;
    }

int main()
{
    string input;
    cin>>input;

    cout<<isValid(input);
    return 0;
}