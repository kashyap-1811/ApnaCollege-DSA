/*For a given integer array of sizeN.
You have to find all the occurrences(indices) of a given element(Key) and print them.
Use a recursive function to solve this problem.*/
#include <iostream>

using namespace std;

void print(int index,int size,int key,int arr[])
{
    if(index==size)
        return;

    if(arr[index]==key)
        cout<<index<<" ";

    print(index+1,size,key,arr);

}

int main()
{
    int size;
    cout<<"Please enter the size of the array: ";
    cin>>size;

    int arr[size];

    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the Value of Key: ";
    cin>>key;

    print(0,size,key,arr);

    return 0;
}