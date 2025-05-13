#include<bits/stdc++.h>
using namespace std;

//global data
vector<vector<int>> arr;
vector<bool> vis;
vector<int> ans;
int cost;

// assign jobs
void assign(int N, int curr_cost, int person, vector<int> &temp_ans)
{
    // if all person are assigned there jobs
    if (person == N)
    {
        if (cost > curr_cost)
        {
            cost = curr_cost; // update cost
            for (int i = 0; i < N; i++)
                ans[i] = temp_ans[i]; // Store the job assignment solution
        }
        return;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap

    // Iterate through all jobs to assign them
    for (int i = 0; i < N; i++)
    {
        if (!vis[i]) // If job i is not yet assigned
        {
            int lb = arr[person][i] + curr_cost; // Lower bound cost of current assignment

            if (person == N - 1)
            {
                pq.push({lb, i});
                break;
            }

            for (int p = person + 1; p < N; p++)
            {
                int mini = INT_MAX;
                for (int j = 0; j < N; j++)
                {
                    if (!vis[j] && j != i)           // If job j is not assigned
                        mini = min(mini, arr[p][j]); // Get the minimum cost for the next worker
                }
                lb += mini;
            }
            pq.push({lb, i}); //push lower bound in pq
        }
    }

    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1 = pq;
    // cout<<"pq for person: "<<person<<endl;
    // while(!pq1.empty())
    // {
    //     cout<<pq1.top().first<<" "<<pq1.top().second<<endl;
    //     pq1.pop();
    // }
    // cout<<endl;

    while (!pq.empty())
    {
        if (pq.top().first <= cost)
        {                                       // if current lb is less than the minimum cost
            vis[pq.top().second] = true;        // Mark job as assigned
            temp_ans[person] = pq.top().second; // Record the assigned job for the current person

            assign(N, curr_cost + arr[person][pq.top().second], person + 1, temp_ans); // Recurse for the next person

            vis[pq.top().second] = false; // Mark job as not-assigned
        }
        // cout<<pq.top().first<<" "<<person<<endl;
        pq.pop();
    }
}

// Function to find the minimum cost of assignment
// of jobs to persons
int assignmentProblem(int Arr[], int N)
{
    // Convert input array to 2D matrix
    int x = 0;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < N; j++)
            temp.push_back(Arr[x++]);
        arr.push_back(temp);
    }

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++)
    //         cout<<arr[i][j]<<" ";
    //     cout<<endl;
    // }

    // cout<<"--------------------------"<<endl;

    cost = INT_MAX;    // Initialize the minimum cost
    int curr_cost = 0; // Start with zero cost

    // Initialize visited array and answer array
    vis.resize(N, false);
    ans.resize(N, -1);

    // Temporary answer vector to store the current assignment
    vector<int> temp_ans(N, -1);

    // call to main function
    assign(N, curr_cost, 0, temp_ans);

    for(int i=0; i<N; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    // Return the minimum cost
    return cost;
}

int main()
{
    int N;
    cin>>N;
    int* arr = new int[N * N];

    for (int i = 0; i < N * N; i++)
        cin >> arr[i];

    cout << assignmentProblem(arr, N);

    delete[] arr;
    return 0;
}

/* 
Sample Inputs:
TYPE:
input for N
array for N*N elements


2
3 5 10 1
Answer: 4

4
9 2 7 8 6 4 3 7 5 8 1 8 2 2 5 1
Answer: 10

3
2 1 2 9 8 1 1 1 1
Answer: 3

4
90 75 75 80 30 85 55 65 125 95 90 105 45 110 95 115
Answer: 275

3
2500 4000 3500 4000 6000 3500 2000 4000 2500
Answer: 9500

4
82 83 69 92 77 37 49 92 11 69 5 86 8 9 98 23
Answer: 140
*/