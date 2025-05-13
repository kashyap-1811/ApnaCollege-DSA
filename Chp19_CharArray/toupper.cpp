#include <iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main()
{
    cout<<"Enter size of the array: ";
    int size;cin>>size;
    cin.ignore();

    char str[size];
    cin.getline(str,size);

    for(int i=0;i<=strlen(str);i++)
    {
        str[i]=toupper(str[i]);
    }
    cout<<str;
    return 0;
}