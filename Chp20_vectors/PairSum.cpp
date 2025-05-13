#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>vec;

    int temp;
    cout<<"Enter the vector elements: "<<endl;
    while(cin>>temp)
    {
        vec.push_back(temp);
        if(temp<0)
            break;
    }

    cout<<"size of the Vector is: "<<vec.size()<<endl;

    int target;
    cout<<"Enter the target sum: ";
    cin>>target;

    int sum=0;
    int start=0,end=vec.size()-2;

    while(start<end)
    {
        sum=vec.at(start)+vec.at(end);
        if(sum==target)
        {
            cout<<"vector["<<start<<"]["<<end<<"]="<<vec.at(start)<<"+"<<vec.at(end)<<"="<<sum<<endl;
            break;
        }
        else if(sum>target)
        {
            end--;
        }
        else if(sum<target)
        {
            start++;
        }
    }
    return 0;
}