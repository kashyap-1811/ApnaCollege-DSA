#include <iostream>

using namespace std;

int countSet(int num)
{
    int count=0;
    
    while(num>0)
    {
        int remainder=num%2;
        count+=remainder;
        num/=2;
    }
    return count;
}

int main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    int count=countSet(num);

    cout<<"Total 1's in the number are: "<<count;
    return 0;
}