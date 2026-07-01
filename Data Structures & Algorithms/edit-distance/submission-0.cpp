class Solution {
public:
    // int func(int i,int j,string s,string t){
    //     if(i<0)return j+1;
    //     if(j<0)return i+1;
    //     if(s[i]==t[j]){
    //         return func(i-1,j-1,s,t);
    //     }
    //     return 1+min({func(i,j-1,s,t),func(i-1,j,s,t),func(i-1,j-1,s,t)});
    // }
    int minDistance(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        vector<long long> prev(m+1,0),cur(m+1,0);
        for(int i=0;i<=m;i++)prev[i]=i;
        //for(int i=0;i<=n;i++)dp[i][0]=i;
        cur[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    //dp[i][j]=dp[i-1][j-1];
                    cur[j]=prev[j-1];
                }
                else{
                   // dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                   cur[j]=1+min({cur[j-1],prev[j-1],prev[j]});
                }
            }
            prev=cur;
            cur[0]++;
        }
        //return dp[n][m];
        return prev[m];
    }
};