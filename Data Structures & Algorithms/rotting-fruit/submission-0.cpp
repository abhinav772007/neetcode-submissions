class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int out=0;
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> dr={-1,1,0,0},dc={0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)pq.push({0,{i,j}});
            }
        }
        vector<vector<int>> disi(n,vector<int>(m,0));
        while(!pq.empty()){
            int dis=pq.top().first,x=pq.top().second.first,y=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=x+dr[i],nc=y+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    disi[nr][nc]=dis+1;
                    pq.push({dis+1,{nr,nc}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
                out=max(out,disi[i][j]);
            }
        }
        return out;
    }
};
