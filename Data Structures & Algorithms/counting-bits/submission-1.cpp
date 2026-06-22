class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,-1);
        if(n==0)return {0};
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int temp=i&1;
            dp[i]=temp+dp[i/2];
        }
        return dp;
    }
};
