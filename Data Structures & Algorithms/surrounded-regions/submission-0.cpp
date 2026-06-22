class Solution {
public:
vector<vector<int>> vis;
vector<int> dr={-1,1,0,0},dc={0,0,-1,1};
int n,m;
void dfs(int i,int j,vector<vector<char>>& board){
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int nr=i+dr[k],nc=j+dc[k];
        if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && board[nr][nc]=='O'){
            dfs(nr,nc,board);
        }
    }
}
    void solve(vector<vector<char>>& board) {
         n=board.size();
         m=board[0].size();
        vis.assign(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(vis[0][j]==0 && board[0][j]=='O')dfs(0,j,board);
            if(vis[n-1][j]==0 && board[n-1][j]=='O')dfs(n-1,j,board);
        }
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0]=='O')dfs(i,0,board);
            if(vis[i][m-1]==0 && board[i][m-1]=='O')dfs(i,m-1,board);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1)board[i][j]='X';
            }
            //cout<<"\n";
        }
        

    }
};
