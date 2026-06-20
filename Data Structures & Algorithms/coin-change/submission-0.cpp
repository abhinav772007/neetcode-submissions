class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e9);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int x=1e9;
            for(auto ru:coins){
                if(ru<=i)x=min(x,1+dp[i-ru]);
            }
            dp[i]=x;
        }
        if(dp[amount]==1e9)return -1;
        return dp[amount];
    }
};
