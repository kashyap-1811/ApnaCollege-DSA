#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>>board,int *arr,int n)
{
    for(int i=9;i>=0;i--)
    {
        cout<<"\t\t\t\t\t";
        for(int k=0;k<12;k++)
        {
            cout<<"-----";
        }
        cout<<endl;

        cout<<"\t\t\t\t\t";
        for(int j=0;j<10;j++)
        {
            bool flag = true;
            for(int k=0;k<n;k++)
            {
                if(arr[k]>=100 && board[i][j] == 99)
                {
                    cout<<"| "<<"*"<<k<<" |";
                    flag = false;;
                    break;
                }
                if(arr[k] == board[i][j]+1)
                {
                    cout<<"| "<<"*"<<k<<" |";
                    flag = false;;
                    break;
                }
            }
            if(flag == false)
                continue;
            if(board[i][j] == 99)
                cout<<"| "<<"YA"<<" |";
            else if(board[i][j] < 9)
                cout<<"| "<<"0"<<board[i][j]+1<<" |";
            else
                cout<<"| "<<board[i][j]+1<<" |";
        }
        cout<<endl;
    }

    cout<<"\t\t\t\t\t";
    for(int k=0;k<12;k++)
        {
            cout<<"-----";
        }
        cout<<endl;
}

int snakes(int currPosition)
{
    if(currPosition == 32)
        return 10;
    if(currPosition == 36)
        return 6;
    if(currPosition == 48)
        return 26;
    if(currPosition == 62)
        return 18;
    if(currPosition == 88)
        return 24;
    if(currPosition == 95)
        return 56;
    if(currPosition == 97)
        return 78;
    return currPosition;
}

int ladders(int currPosition)
{
     if(currPosition == 2)
        return 38;
    if(currPosition == 4)
        return 14;
    if(currPosition == 8)
        return 30;
    if(currPosition == 21)
        return 42;
    if(currPosition == 28)
        return 74;
    if(currPosition == 50)
        return 67;
    if(currPosition == 71)
        return 92;
    if(currPosition == 80)
        return 99;
    return currPosition;
}

int main()
{
    vector<vector<int>>board;
    int k = 0;
    // creating board
    for(int i=0;i<10;i++)
    {
        vector<int>temp;
        if(k%2 == 0)
        {    for(int j=0;j<10;j++)
            {
                temp.push_back(i*10 + j);
            }
        }
        else{
            for(int j=9;j>=0;j--)
            {
                temp.push_back(i*10 + j);
            }
        }
        k++;
        board.push_back(temp);
    }

    int n;
    cout<<"Enter number of players: ";
    cin>>n;

    int arr[n]={0};
    bool flag = true;

    while(1)
    {
        for(int i=0;i<n;i++)
        {
            cout<<"Player No: "<<i<<endl;

            char input;
            cout<<"Press any key for input: ";
            cin>>input;
            
            // Initialize random seed
            std::srand(std::time(0));

            // Generate a random number between 1 and 6
            int dice = (std::rand() % 6) + 1;
            cout<<"Dice Shows: "<<dice<<endl;

            arr[i] += dice;
            int change = 0;
            change = snakes(arr[i]);
            if(change != arr[i])
            {
                cout<<"Snake Bite: Reached from: "<<arr[i]<<" to "<<change<<endl;
                arr[i] = change;
            }
            change = ladders(arr[i]);
            if(change != arr[i])
            {
                cout<<"Wow! Ladder: Reached from: "<<arr[i]<<" to "<<change<<endl;
                arr[i] = change;
            }
            
            //current postion print
            cout<<"You Reached: "<<arr[i]<<endl;

            for(int j=0;j<n;j++)
            {
                if(arr[j] > 100)
                    cout<<"player ["<<j<<"] at "<<arr[j]<<"\t";
                else
                    cout<<"player ["<<j<<"] at "<<arr[j]<<"\t";
            }
            cout<<endl;
            print(board,arr,n);

            for(int i=0;i<n;i++)
            {
                if(arr[i] >= 100)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false)
                break;

            char ch;
            cout<<"Enter c for continue: ";
            cin>>ch;
            system("cls");
        }

        if(flag == false)
                break;
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i] >= 100)
        {
            cout<<"\t\t\tWOW! player["<<i<<"] Won!!!!!!";
        }
    }
    return 0;
}