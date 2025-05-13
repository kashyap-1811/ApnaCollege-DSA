#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    bool flag=true;
    cout<<"Enter the Size of the string: ";
    int size;cin>>size;
    cin.ignore();

    char str[size+1];
    cin.getline(str,size+1);

    for(int i=0;i<=strlen(str)/2;i++)
    {
        if(str[i]==str[strlen(str)-i-1])
        {
            //continue
        }
        else
        {
            cout<<"Given String is not Palindrome.";
            flag=false;
            break;
        }
    }
    if(flag==true)
    {
        cout<<"Given String is Palindrome.";
    }
    return 0;
}