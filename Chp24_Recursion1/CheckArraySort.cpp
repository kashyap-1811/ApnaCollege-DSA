#include <iostream>

using namespace std;

bool isSort(int *arr,int n,int i)
{
    if(i==n-1)
        return true;

    if(arr[i]>arr[i+1])
        return false;

    return isSort(arr,n,i+1);
}

int main()
{
    int size;
    cout<<"Please enter the size of the array: ";
    cin>>size;

    int *p= (int*)malloc(size*sizeof(int));

    for(int i=0;i<size;i++)
    {
        cout<<"Enter the value at index: ["<<i<<"]: ";
        cin>>*(p+i);
    }

    cout<<isSort(p,size,0);
    return 0;
}