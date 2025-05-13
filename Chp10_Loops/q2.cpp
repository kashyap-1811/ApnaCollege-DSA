//WAPtoprintthemultiplicationtableofanumber,enteredbytheuser

#include <iostream>

using namespace std;

int main()
{
    int table;
    cout<<"Enter the Number: ";
    cin>>table;

    for(int i=1;i<=10;i++)
    {
        cout<<table<<"*"<<i<<"="<<table*i<<endl;
    }
    return 0;
}