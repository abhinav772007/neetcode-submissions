class Solution {
public:
// int spanningTree(int V, vector<vector<int>> adj[])
// 	{
// 		priority_queue<pair<int, int>,
// 		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

// 		vector<int> vis(V, 0);
// 		// {wt, node}
// 		pq.push({0, 0});
// 		int sum = 0;
// 		while (!pq.empty()) {
// 			auto it = pq.top();
// 			pq.pop();
// 			int node = it.second;
// 			int wt = it.first;

// 			if (vis[node] == 1) continue;
// 			// add it to the mst
// 			vis[node] = 1;
// 			sum += wt;
// 			for (auto it : adj[node]) {
// 				int adjNode = it[0];
// 				int edW = it[1];
// 				if (!vis[adjNode]) {
// 					pq.push({edW, adjNode});
// 				}
// 			}
// 		}
// 		return sum;
// 	}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n;i++){
            int x=points[i][0],y=points[i][1];
            for(int j=i+1;j<n;j++){
                int temp1=points[j][0],temp2=points[j][1];
                int dis=abs(x-temp1)+abs(y-temp2);
                adj[i].push_back({dis,j});
                adj[j].push_back({dis,i});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(n,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            int dis=pq.top().first,x=pq.top().second;
            pq.pop();
            if(vis[x]==1)continue;
            vis[x]=1;
            sum+=dis;
            for(auto temp:adj[x]){
                int temp1=temp.first,temp2=temp.second;
                if(vis[temp2]==0){
                    pq.push({temp1,temp2});
                }
            }
        }
        return sum;
    }
};
