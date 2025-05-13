#include <iostream>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;

    if(str1.length()==str2.length())
    {
        int count=0,diff=0;
        for(int i=0;i<str1.length();i++)
        {
            if(str1[i]!=str2[i]&&diff%2==0)
            {
                count+=(str2[i]-str1[i]);
                diff++;
            }
            else if(str1[i]!=str2[i]&&diff%2!=0)
            {
                count+=(str2[i]-str1[i]);
                diff++;
            }
            if(count==0&&diff==2)
            {
                cout<<"true: Possible";
                return 0;
            }
        }
    }

    cout<<"false: Not Possible";
    return 0;
}