//Question2:PrinttheRhombusPattern.
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of lines: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int sp=0;sp<(n-i);sp++)
            cout<<" ";

        for(int j=0;j<n;j++)
            cout<<"*";

            cout<<endl;
    }
    return 0;
}