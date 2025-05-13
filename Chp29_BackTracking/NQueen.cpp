#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<char>>board)
{
    int n=board.size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------------------\n";
}

bool isSafe(vector<vector<char>>board , int row ,int col)
{
    for(int i=0;i<row;i++)
    {
            if(board[i][col]=='Q')
            {
                return false;
            }
    }

    int i=row;
    int j=col;

    while(i>=0 && j>=0)
    {
        if(board[i][j]=='Q')
            return false;
        i--;
        j--;
    }

    i=row;
    j=col;

    while(j<board.size() && i>=0)
    {
        if(board[i][j]=='Q')
            return false;
        i--;
        j++;
    }

    return true;
}

void Nqueens(vector<vector<char>>board , int row)
{
    int n=board.size();

    static int count=0;
    if(row == n)
    {
        count++;
        print(board);
        cout<<"Count : "<<count<<endl;
        return;
    }

    for(int j=0;j<n;j++)
    {
        if(isSafe(board,row,j))
        {
            board[row][j]='Q';
            Nqueens(board,row+1);
            board[row][j]='.';
        }
    }
}

int main()
{
    vector<vector<char>>board;
    int n=4;

    for(int i=0;i<n;i++)
    {
        vector<char>row;
        for(int j=0;j<n;j++)
        {
            row.push_back('.');
        }
        board.push_back(row);
    }

    Nqueens(board,0);
    return 0;
}