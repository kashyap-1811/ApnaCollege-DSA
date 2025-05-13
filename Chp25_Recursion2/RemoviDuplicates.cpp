#include <iostream>
#include<string>

using namespace std;

void removeDuplicate(string str,string ans,int i,int map[])
{

    if(i==str.size())
    {
        cout<<"After removing the Duplicates the ans is: "<<ans;
        return;
    }

    int index=int(str[i]-'a');

    if(map[index])
    {
        removeDuplicate(str,ans,i+1,map);
    }
    else
    {
        map[index]=true;
        removeDuplicate(str,ans+str[i],i+1,map);
    }
}

int main()
{
    string  str;
    cout<<"Enter the strings: ";
    cin>>str;
    string ans="";
    int map[26]={false};

    removeDuplicate(str,ans,0,map);

    return 0;
}