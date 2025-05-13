//WriteaC++programthattakesayearfromtheuserandprintwhetherthatyearisaleapyearornot

#include<iostream>
using namespace std;

int main()
{
    int year;
    cout<<"Enter year: ";
    cin>>year;

    if(year%400==0||(year%4==0&&year%100!=0))
    {
        cout<<"Entered year is a Leap Year";
    }
    else{
        cout<<"Entered Year is not a Leap Year";
    }
    return 0;
}