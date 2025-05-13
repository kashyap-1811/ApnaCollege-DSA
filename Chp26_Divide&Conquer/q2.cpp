#include <iostream>

using namespace std;

int majority(int *arr,int n)
{
    
}

int main()
{
    int size;
    cout<<"Enter Size of the element: ";
    cin>>size;

    int arr[size];

    cout<<"Enter the elements of the Array: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    cout<<"Majority element is: "<<majority(arr,size-1);
    return 0;
}