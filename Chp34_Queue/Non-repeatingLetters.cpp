#include <bits/stdc++.h>

using namespace std;

char non_repeating_letter(string str)
{
    int freq[26]={0};
    queue<char>q;
    for(char c : str)
    {
        q.push(c);
        freq[c-'a']++;
    }
    while(freq[q.front()-'a'] != 1 && !q.empty())
    {
        q.pop();
    }
    if(q.empty())
    {
        return '!';
    }
    return q.front();
}

int main()
{
    string str="ghhttyg";

    cout<<non_repeating_letter(str);
    return 0;
}