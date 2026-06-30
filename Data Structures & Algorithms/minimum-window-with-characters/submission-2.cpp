class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        unordered_map<char,int> mp;
        for(auto x:t)mp[x]++;
        int l=0,ct=0,n=s.size(),m=t.size();
        int lout,rout;
        int out=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp[s[i]]>0)ct++;
            mp[s[i]]--;
            
            while(ct==m){
                if (i - l + 1 < out) {
    out = i - l + 1;
    lout = l;
}
                mp[s[l]]++;
                if(mp[s[l]]>0)ct--;
                l++;
            }
        }
        if(out==INT_MAX)return "" ;
        return s.substr(lout,out);
    }
};
