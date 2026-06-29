class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<pair<int,int>> adj[n+1];
       for(auto x:times){
        adj[x[0]].push_back({x[1],x[2]});
       }
        vector<int> dis(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dis[k]=0;
        while(!pq.empty()){
            int disi=pq.top().first,x=pq.top().second;
            pq.pop();
            for(auto z:adj[x]){
                if(disi+z.second<dis[z.first]){
                    dis[z.first]=disi+z.second;
                    pq.push({dis[z.first],z.first});
                }
            }
        }
        int out=INT_MIN;
        for(int i=1;i<=n;i++){
            int x=dis[i];
            if(x==0)continue;
            if(x==1e9)return -1;
            out=max(out,x);
        }
        return out;
    }
};
