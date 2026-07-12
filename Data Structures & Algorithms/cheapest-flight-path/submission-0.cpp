class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
           // adj[x[1]].push_back({x[0],x[2]});
        }
        queue<pair<int,pair<int,int>>> pq;
        vector<int> dis(n,1e9);
        dis[src]=0;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            int stop=pq.front().first,nod=pq.front().second.first,disi=pq.front().second.second;
            pq.pop();
           if(stop>k)continue;
           for(auto it:adj[nod]){
            if(dis[it.first]>disi+it.second && stop<=k ){
                dis[it.first]=disi+it.second;
                pq.push({stop+1,{it.first,dis[it.first]}});
            }
           }
        }
        
        if(dis[dst]==1e9)return -1;
        return dis[dst];

    }
};
