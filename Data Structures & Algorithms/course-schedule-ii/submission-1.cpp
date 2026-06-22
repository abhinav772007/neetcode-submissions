class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> inn(n,0);
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
            inn[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inn[i]==0)q.push(i);
        }
        vector<int> out;
        while(!q.empty()){
            int fir=q.front();
            out.push_back(fir);
            q.pop();
            for(auto x:adj[fir]){
                inn[x]--;
                if(inn[x]==0)q.push(x);
            }
        }
        if(out.size()!=n)return {};
        return out;
    }
};
