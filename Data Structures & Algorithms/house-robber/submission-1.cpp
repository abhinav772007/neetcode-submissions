class Solution {
public:
// int func(int i,vector<int> &nums){
//     if(i==0)return nums[0];
//     if(i<0)return 0;
//     return max(nums[i]+func(i-2,nums),func(i-1,nums));
// }
    int rob(vector<int>& nums) {
        //return func(nums.size()-1,nums);
        int n=nums.size();
        //vector<int> dp(n+1,0);
        //dp[0]=0;
        //dp[1]=nums[0];
        int x=0,y=nums[0];
        for(int i=2;i<=n;i++){
            int temp=y;
            //dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
            y=max(nums[i-1]+x,y);
            x=temp;
        }
        //return dp[n];
        return y;
    }
};
