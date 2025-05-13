#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    cout<<"Enter the Size of the string: ";
    int size;cin>>size;
    cin.ignore();

    char str[size+1];
    cin.getline(str,size+1);
    int n=strlen(str);
    cout<<n<<endl;

    for(int i=0;i<=strlen(str)/2;i++)
    {
        swap(str[i],str[strlen(str)-i-1]);
    }
    cout<<"Reversed String is: "<<str;
    return 0;
}