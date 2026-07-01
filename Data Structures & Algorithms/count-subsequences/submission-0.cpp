class Solution {
public:
    // int func(int i,int j,string &s,string &t,vector<vector<int>> &dp){
    //     if(j<0)return 1;
    //     if(i<0)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s[i]==t[j]){
    //         return dp[i][j]=func(i-1,j-1,s,t,dp)+func(i-1,j,s,t,dp);
    //     }
    //     else{
    //         return dp[i][j]=func(i-1,j,s,t,dp);
    //     }
    // }
    int numDistinct(string s, string t) {
        
        int n=s.size(),m=t.size();
        vector<unsigned long long> cur(m+1,0);
        cur[0]=1;
        //for(int j=0;j<=m;j++)dp[0][j]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
             cur[j]=cur[j-1]+cur[j];
        }
       
            }
        }
        return cur[m];
    }
};