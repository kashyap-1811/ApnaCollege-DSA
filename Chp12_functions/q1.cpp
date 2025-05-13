//palindrome check

#include <iostream>

using namespace std;

int check_palindrome(int number)
{
    int result=0;
    while(number!=0)
    {
        int temp=number%10;
        result=result*10+temp;
        number/=10;
    }
    return result;
}

int main()
{
    int number;
    cout<<"Provide the number: ";
    cin>>number;

    int reverse=check_palindrome(number);

    if(number==reverse)
    {
        cout<<"Given Number is Palindrome";
    }
    else
    {
        cout<<"Givenn Number is not Palindrome";
    }
    return 0;
}