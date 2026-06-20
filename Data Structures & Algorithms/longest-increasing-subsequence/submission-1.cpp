class Solution {
public:
vector<vector<int>> dp;
int func(int i,int target,vector<int> &nums){
    if(i==0){
        if(nums[i]+1000<target)return 1;
        return 0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    if(nums[i]+1000>=target)return func(i-1,target,nums);
    //return max(1+func(i-1,nums[i]-1+1000,nums),func(i-1,target,nums));
     return dp[i][target]=max(1+func(i-1,nums[i]+1000,nums),func(i-1,target,nums));
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(2002,-1));
        return func(n-1,2001,nums);
    }
};
