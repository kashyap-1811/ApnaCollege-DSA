/*WearegivenastringS,weneedtofindthecountofallcontiguoussubstringsstartingandendingwiththesamecharacter.
[LeetcodePremiumQs]*/

#include <iostream>
#include<string>
using namespace std;

int FindSubstring(string str,int first,int last,int res)
{
    if(first==str.size())
        return res;

    if(str[first]==str[last])
    {
        res++;
    }
    
    if(last==str.size())
    {
        first++;
        last=first-1;
    }

    return FindSubstring(str,first,last+1,res);
}

int main()
{
    string str;
    cout<<"Enter the String: ";
    cin>>str;

    cout<<FindSubstring(str,0,0,0);
    return 0;
}