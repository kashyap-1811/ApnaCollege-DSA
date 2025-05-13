#include <iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int>v, int target,int i)
{
    if(i==v.size())
        return -1;

    if(target==v.at(i))
        return i;

    return firstOccurence(v,target,i+1);
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
    cout<<"First Occurence of Targerted Element is: "<<firstOccurence(vect,target,0);

    return 0;
}