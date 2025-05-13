#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    
    int maxi = nums[0];
    int start = 0, end = 0; // the final start and end position of the maximum sum subarray
    
    int sum = 0;
    int s = 0; // the temporary start position
    
    for(int i=0;i<n;i++){
        
        sum += nums[i];
        
        if(sum > maxi){
            maxi = sum;
            start = s;
            end = i;
        }
        
        if(sum < 0){
            sum = 0;
            s = i+1;
        }   
    }
    
    cout<<"Maximum Sum Subarray from nums["<<start<<"] = "<<nums[start]<<" till nums["<<end<<"] = "<<nums[end]<<endl;
    
    return maxi; 
}

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<maxSubArray(nums);
    return 0;
}