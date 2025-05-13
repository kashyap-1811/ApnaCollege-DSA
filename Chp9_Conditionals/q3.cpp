//Forany3digitnumbercheckwhetherit’sanArmstrongnumberornot.
///Armstrongnumberisanumberthatisequaltothesumofcubesofitsdigits

#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    cout<<"Enter the number: ";
    int n;cin>>n;
    int a=n;
    int sum=0;
    int digits=0;
    //for digits
    while(a!=0)
    {
        a/=10;
        digits++;
    }
    a=n;
    while(a!=0)
    {
        int temp=a%10;
        sum+=pow(temp,digits);
        a/=10;
    }
    cout<<"Sum is:"<<sum<<endl;
    if(sum==n)
    {
        cout<<"Entered number is Armstrong";
    }
    else{
        cout<<"Entered number is not a Armstrong";
    }
    return 0;
}