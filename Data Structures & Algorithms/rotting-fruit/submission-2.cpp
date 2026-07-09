class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dr={0,0,1,-1},dc={1,-1,0,0};
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> tim(n,vector<int> (m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==2){
                pq.push({0,{i,j}});
               tim[i][j]=0;
               }
            }
        }
        while(!pq.empty()){
            int x=pq.top().second.first,y=pq.top().second.second,time=pq.top().first;
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=x+dr[i],nc=y+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    pq.push({time+1,{nr,nc}});
                    tim[nr][nc]=time+1;
                }
            }
        }
        int out=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
                if(tim[i][j]!=INT_MAX)out=max(out,tim[i][j]);
            }
        }
        return out;
    }
};
