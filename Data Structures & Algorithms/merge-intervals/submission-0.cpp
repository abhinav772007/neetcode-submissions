class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int maxi=0;
       for(auto &x:intervals){
        maxi=max(maxi,x[0]);
       } 
       vector<int> mp(maxi+1,0);
       for(auto& x:intervals){
        int st=x[0],en=x[1];
        mp[st]=max(en+1,mp[st]);
       }
       vector<vector<int>> out;
       int have=-1;
       int ist=-1;
       for(int i=0;i<mp.size();i++){
        if(mp[i]!=0){
            if(ist==-1)ist=i;
            have=max(mp[i]-1,have);
        }
        if(have==i){
            out.push_back({ist,have});
            have=-1;
            ist=-1;
        }
       }
       if(ist!=-1)out.push_back({ist,have});
       return out;
    }
};
