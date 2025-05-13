//              BRUTE FORCE
// #include <bits/stdc++.h>
// /*
//     Span= max. no of consecutive days(including current) for which price<=today's price;
// */
// using namespace std;

// int main()
// {
//     int size;
//     cout<<"Enter Size of the element: ";
//     cin>>size;

//     int arr[size];

//     cout<<"Enter the elements of the Array: ";
//     for(int i=0;i<size;i++)
//     {
//         cin>>arr[i];
//     }

//     int ans[size];

//     for(int i=0;i<size;i++)
//     {
//         ans[i]=1;
//         for(int j=i-1;j>=0;j--)
//         {
//             if(arr[i]<arr[j])
//             {
//                 break;
//             }
//             else{
//                 ans[i]++;
//             }
//         }
//     }

//     for(int i=0;i<size;i++)
//         cout<<ans[i]<<" ";

//     return 0;
// }


//              Improved Code
#include <bits/stdc++.h>

using namespace std;

void StockSpan(int *arr, vector<int>&span , int size)
{
    stack<int>s;
    s.push(0);

    for(int i=1;i<size;i++)
    {
        int currValue=arr[i];
        while(!s.empty() && currValue>=arr[s.top()])
        {
            s.pop();
        }

        if(s.empty())
        {
            span[i]=i+1;
        }
        else{
            int prevHigh=s.top();
            span[i]=i-prevHigh;
        }
    }
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

    vector<int>span(size);
    span[0]=1;

    StockSpan(arr,span,size);

    for(int i=0;i<span.size();i++)
        cout<<span.at(i)<<" ";

    return 0;
}