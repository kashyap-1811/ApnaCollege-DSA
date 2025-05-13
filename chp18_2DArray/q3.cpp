#include <iostream>

using namespace std;

int main()
{
    int row,col;
    cout<<"Enter no. of rows: ";
    cin>>row;
    cout<<"Enter no. of column: ";
    cin>>col;

    int arr[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<"Enter the element at index: ["<<i<<"]["<<j<<"]: ";
            cin>>arr[i][j];
        }
    }

    if(row!=col)//for rectangle matrix
    {
        int brr[col][row];

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                brr[j][i]=arr[i][j];
            }
        }

        for(int i=0;i<col;i++)
        {
            for(int j=0;j<row;j++)
            {
                cout<<brr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else//for square matrix
    {
        for(int i=0;i<row;i++)
        {
            for(int j=i+1;j<col;j++)
            {
                int temp=arr[j][i];
                arr[j][i]=arr[i][j];
                arr[i][j]=temp;
            }
        }
        cout<<endl;
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<row;j++)
            {
                 cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}