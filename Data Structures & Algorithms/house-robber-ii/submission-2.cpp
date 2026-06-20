class Solution {
public:
    int rob(vector<int>& nums) {
         //return func(nums.size()-1,nums);
         if(nums.size()==1)return nums[0];
         //if(nums.size()==2)return 0;
        int out=0;
        int n=nums.size();
        //vector<int> dp(n+1,0);
        //dp[0]=0;
        //dp[1]=nums[0];
        int x=0,y=nums[0];
        for(int i=2;i<n;i++){
            int temp=y;
            //dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
            y=max(nums[i-1]+x,y);
            x=temp;
        }
        //return dp[n];
        out= y;
         //return func(nums.size()-1,nums);
        
         x=0,y=nums[1];
        for(int i=3;i<=n;i++){
            int temp=y;
            //dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
            y=max(nums[i-1]+x,y);
            x=temp;
        }
        //return dp[n];
        return max(out,y);
    }
};
