//PrintthePalindromicPatternwithNumbers.
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of lines: ";
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int sp=1;sp<=(n-i);sp++)
            cout<<" ";;

        for(int j=i;j>0;j--)
            cout<<j;
        
        for(int j=2;j<=i;j++)
            cout<<j;

        cout<<endl;
    }
    return 0;
}