#include <iostream>

using namespace std;

int give_bit_value(int num,int bit_mask)
{
    num=num&bit_mask;
    if(num==0)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

int main()
{
    int num;
    cout<<"Enter the Number: ";
    cin>>num;

    int bit;
    cout<<"Enter which bit to change: ";
    cin>>bit;//bit variable is which bit to change

    int bit_mask=1;
    bit_mask=bit_mask<<bit;//bit_mask variable is mask value
    // cout<<bit_mask<<endl;

    int bit_value=give_bit_value(num,bit_mask);

    if(bit_value==0)
    {
        num=num|bit_mask;
        cout<<"After setting the Bit to 1: ";
        cout<<num;
    }
    else
    {
        bit_mask=~(bit_mask);
        num=(num&bit_mask);
        cout<<"After setting the Bit to 0: ";
        cout<<num;
    }
    return 0;
}