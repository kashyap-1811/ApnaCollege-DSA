#include <iostream>
#include<string>
using namespace std;

int main()
{
    string str1,str2;
    cout<<"Give Input of two strings: ";
    getline(cin,str1,' ');
    getline(cin,str2);

    int arr[26]={0};

    if(str1.length()==str2.length())
    {
        for(int i=0;i<str1.length();i++)
        {
            arr[str1[i]-'a']++;
            arr[str2[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=0)
            {
                cout<<"They are not valid anagrams.";
                return 0;
            }
        }
        cout<<"They are valid anagrams.";
    }
    else
    {
        cout<<"They are not valid anagrams.";
    }
    return 0;
}