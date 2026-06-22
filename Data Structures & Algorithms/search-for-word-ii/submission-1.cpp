class Solution {
public:
vector<int> dr={-1,1,0,0},dc={0,0,1,-1};
    bool dfs(int ct,string &s,int x,int y,vector<vector<char>>& board,vector<vector<int>> &vis){
        if(ct==s.size())return true;
        vis[x][y]=1;
        int n=board.size(),m=board[0].size();
        
        for(int i=0;i<4;i++){
            int nr=x+dr[i],nc=y+dc[i];
            
            if(nr<n && nr>=0 && nc<m && nc>=0 && board[nr][nc]==s[ct] && vis[nr][nc]==0){
                if(dfs(ct+1,s,nr,nc,board,vis)) {
                    vis[x][y]=0;
                    return true;
                }
            }
        }
       vis[x][y]=0;
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       vector<string> out;
       for(auto word:words){
       int n=board.size(),m=board[0].size();
       bool found = false;
        for(int i=0;i<n && !found;i++){
            for(int j=0;j<m && !found;j++){
                vector<vector<int>> vis(n,vector<int>(m,0));
                if(board[i][j]==word[0] && dfs(1,word,i,j,board,vis)) {
                    out.push_back(word);
                    found = true;
                }
            }
        }}
        return out;
         
    }
};