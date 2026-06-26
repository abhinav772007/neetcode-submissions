class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<int> dr={0,0,1,-1},dc={-1,1,0,0};
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    pq.push({0,{i,j}});
                }
            }
        }
        while(!pq.empty()){
            int dis=pq.top().first,i=pq.top().second.first,j=pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int nr=i+dr[k],nc=j+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!=-1 && grid[i][j]+1<grid[nr][nc]){
                    grid[nr][nc]=1+grid[i][j];
                    pq.push({grid[nr][nc],{nr,nc}});
                }
            }
        }
        
    }
};
