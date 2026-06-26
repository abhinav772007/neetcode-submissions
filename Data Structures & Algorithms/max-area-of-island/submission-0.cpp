class Solution {
public:
    vector<int> dr={0,0,-1,1},dc={1,-1,0,0};
    vector<vector<int>> vis;
    int n,m,ct,maxi=0;
    void dfs(int i,int j,vector<vector<int>>& grid){
        ct++;
       vis[i][j]=1;
       for(int k=0;k<4;k++){
        int nr=i+dr[k],nc=j+dc[k];
        if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1 ){
            dfs(nr,nc,grid);
        }
       }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         n=grid.size(),m=grid[0].size();
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    ct=0;
                    dfs(i,j,grid);
                    maxi=max(maxi,ct);
                    
                }
            }
        }
        return maxi;
    }
};
