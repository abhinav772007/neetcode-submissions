class Solution {
public:
vector<vector<int>> dp;
    // int func(int ind,vector<int>&prices,int buy){
    //     if(ind==prices.size())return 0;
    //     if(dp[ind][buy]!=-1)return dp[ind][buy];
    //     if(buy){
    //         int temp1=-prices[ind]+func(ind+1,prices,0);
    //         int temp2=func(ind+1,prices,1);
    //         return dp[ind][buy]=max(temp1,temp2);
    //     }
    //     else{
    //         int temp1=prices[ind]+func(ind+1,prices,1);
    //         int temp2=func(ind+1,prices,0);
    //         return dp[ind][buy]=max(temp1,temp2);
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //dp.assign(n+2,vector<int>(2,0));
        vector<int> a1(2,0),a2(2,0),a3(2,0);
       //int x=0,y=0;
        for(int i=n-1;i>=0;i--){
            a1[1]=max(-prices[i]+a2[0],a2[1]);
            a1[0]=max(prices[i]+a3[1],a2[0]);
        //    int temp2=y;
        //     y=max(-prices[i]+x,y);
        //     x=max(prices[i]+temp2,x);
        a3=a2;
        a2=a1;
        }
        
       // return y;
       //return dp[0][1];
       return a2[1];
    }
};