#include <bits/stdc++.h>

using namespace std;

bool ValidParenthesis(string input)
{
    stack<char>s;

    for(int i=0;i<input.size();i++)
    {
        if(s.empty())
        {
            s.push(input[i]);
        }
        else if(input[i]==')')
        {
            if(s.top()=='(')
                return false;

            else
            {
                while(s.top()!='(')
                {
                    s.pop();
                }
                s.pop();
            }

        }
        else
        {
            s.push(input[i]);
        }
    }

        return true;

}

int main()
{
    string input;
    cin>>input;

    cout<<ValidParenthesis(input);
    return 0;
}