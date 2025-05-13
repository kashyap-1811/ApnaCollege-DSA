#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
            
        auto start = nums.end()-k;
        auto end = nums.end();
        nums.insert(nums.begin(), start, end);
        nums.erase(nums.begin()+n, nums.end());
}

int main()
{
    int n;
    vector<int>nums = {1,2,3,4,5,6,7,8};
    int k = 9;

    rotate(nums, k);
    for(int i=0; i<nums.size(); i++)
        cout<<nums[i]<<"  ";
    return 0;
}