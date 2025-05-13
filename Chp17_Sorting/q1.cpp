#include <iostream>

using namespace std;
//descending order sorting

//Insertion Sort
void insertion(int *arr,int n)

{
    for(int i=1;i<n;i++)
    {
        int curr=arr[i];
        int pre=i-1;

        while(pre>=0&&arr[pre]<curr)
        
        {
            swap(arr[pre],arr[pre+1]);
            pre--;
        }
    }
}

//Count Sort
void count(int *arr,int n)
{
    int fre[1000]={0};//range
    int minVal=INT32_MAX,maxVal=INT32_MIN;

    for(int i=0;i<n;i++)
    {
        minVal=min(minVal,arr[i]);
        maxVal=max(maxVal,arr[i]);
        fre[arr[i]]++;
    }
    cout<<maxVal<<" "<<minVal<<endl;

    for(int i=maxVal,j=0;i>=minVal;i--)
    {
        while(fre[i]>0)
        {
            arr[j++]=i;
            fre[i]--;
        }
    }
}

//Selection sort
void selection(int *arr,int n)
{
    int min;
    for(int i=0;i<n;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]<arr[j])
                min=j;
        }
        swap(arr[min],arr[i]);
    }
}

//Bubble Sort
void bubble(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    cout<<"Enter the elements of the array: "<<endl;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int ch;
    cout<<"Enter corresponding for sorting technique: "<<endl
    <<"1. Insertion: "<<endl
    <<"2. Count: "<<endl
    <<"3. Selection: "<<endl
    <<"4. Bubble: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
            insertion(arr,size);
            break;
        case 2: 
            count(arr,size);
            break;
        case 3:
            selection(arr,size);
            break;
        case 4:
            bubble(arr,size);
            break;
    }

    cout<<"Array after Sorting: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}