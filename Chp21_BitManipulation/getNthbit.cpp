#include <iostream>

using namespace std;

int main()
{
    int num;
    cout<<"Enter the Number: ";
    cin>>num;

    int bit;
    cout<<"Enter which bit want: ";
    cin>>bit;

    int bit_mask=1;
    bit_mask<<bit;

    if(num&bit_mask==0)
    {
        cout<<"Bit no. "<<bit<<" in "<<num<<" is 0";
    }
    else
    {
         cout<<"Bit no. "<<bit<<" in "<<num<<" is 1";
    }
    return 0;
}