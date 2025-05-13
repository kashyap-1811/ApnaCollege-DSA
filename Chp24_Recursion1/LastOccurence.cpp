#include <iostream>
#include<vector>
using namespace std;

int lastOccurence(vector<int>v, int target,int i)
{
    if(i==-1)
        return -1;

    if(target==v.at(i))
        return i;

    return lastOccurence(v,target,--i);
}

int main()
{
    cout<<"Enter the element of the vector: "<<endl;
    vector<int>vect;
    int temp=0;
    while(temp>=0)
    {
        cin>>temp;
        vect.push_back(temp);
    }

    int target;
    cout<<"Enter the target element: ";
    cin>>target;
    cout<<endl;
    cout<<"Last Occurence of Targerted Element is: "<<lastOccurence(vect,target,vect.size()-1);

    return 0;
}