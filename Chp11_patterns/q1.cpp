// Question1:Printthe0-1TrianglePattern.
// For n=5
// 1
// 01
// 101
// 0101
// 10101

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of lines: ";
    cin>>n;

    int a=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(a%2==0)
            {
                cout<<0;
            }
            else{
                cout<<1;
            }
            a++;
        }
        cout<<endl;
    }
    return 0;
}