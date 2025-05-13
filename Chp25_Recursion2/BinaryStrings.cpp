#include <iostream>
#include<string>
using namespace std;

int BinaryStrings(int size,int index,string str)
{
    if(index==size)
    {
        cout<<str<<endl;
        return 1;
    }

    if(index==0)
    {
        return BinaryStrings(size,index+1,str+"0")+BinaryStrings(size,index+1,str+"1");
    }

    if(str[index-1]=='0')
    {
        return BinaryStrings(size,index+1,str+"0")+BinaryStrings(size,index+1,str+"1");
    }
    else if(str[index-1]=='1')
    {
        return BinaryStrings(size,index+1,str+"0");
    }
    
}

int main()
{
    int size;
    cout<<"Enter the Size of the Strings: ";
    cin>>size;
    string str="";

    cout<<BinaryStrings(size,0,str);

    return 0;
}