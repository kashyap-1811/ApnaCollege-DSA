//Write a recursive function to per form BinarySearch

#include <iostream>

using namespace std;

int BinarySearch(int key,int arr[],int start,int end)
{
    int mid=(start+end)/2;

    if(start>end)
    {
        return -1;
    }

    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        end=mid-1;
        return BinarySearch(key,arr,start,end);
    }
    else if(arr[mid]<key)
    {
        start=mid+1;
        return BinarySearch(key,arr,start,end);
    }
}

int main()
{
    int size;
    cout<<"Please enter the size of the array: ";
    cin>>size;

    int arr[size];

    for(int i=0;i<size;i++)
    {
        cout<<"Enter the value at index: ["<<i<<"]: ";
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the Value of Key: ";
    cin>>key;

    cout<<"Index of Key is: "<<BinarySearch(key,arr,0,size-1);
    
    return 0;
}