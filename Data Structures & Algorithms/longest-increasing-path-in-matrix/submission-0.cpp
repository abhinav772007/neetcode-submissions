class Solution {
public:
vector<int> dr={0,0,-1,1},dc={1,-1,0,0};
int n,m;
vector<vector<int>> dp;
int func(int i,int j,vector<vector<int>>& matrix){
    if(dp[i][j]!=-1)return dp[i][j];
    int maxi=INT_MIN;
    for(int k=0;k<4;k++){
        int nr=i+dr[k],nc=j+dc[k];
        if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]>matrix[i][j])maxi=max(maxi,func(nr,nc,matrix));
    }
    if(maxi==INT_MIN) return dp[i][j]= 1;
    return dp[i][j]=1+maxi;
    
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         n=matrix.size();
         m=matrix[0].size();
        dp.assign(n,vector<int>(m,-1));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(func(i,j,matrix),maxi);
            }
        }
        return maxi;

    }
};
