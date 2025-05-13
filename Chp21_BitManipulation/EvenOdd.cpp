#include <iostream>

using namespace std;

int main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;

    if((num&1)==0)
        cout<<"entered number is Even";
    else
        cout<<"entered number is Odd";    
        return 0;
}