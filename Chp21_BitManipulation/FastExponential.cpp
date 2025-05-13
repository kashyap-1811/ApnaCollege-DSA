#include <iostream>

using namespace std;

int FastExponential(int num,int power)
{
    int sum=1;
    while(power>0)
    {
        int remainder=power%2;
        if(remainder==1)
            sum*=(num*remainder);
        num*=num;
        power/=2;
    }
    return sum;
}

int main()
{
    int ans;
    int base;
    cout<<"Enter the value of base: ";
    cin>>base;

    int power;
    cout<<"enter the value of Power: ";
    cin>>power;

    ans=FastExponential(base,power);

    cout<<"Ans is: "<<ans;
    return 0;
}