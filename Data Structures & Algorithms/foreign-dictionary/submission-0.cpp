class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> indegree;
        for(string w:words){
            for(char c:w){
                adj[c]=unordered_set<char>();
                indegree[c]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i],w2=words[i+1];
            int minlen=min(w1.size(),w2.size());
            if(w1.size()>w2.size() && w1.substr(0,minlen)==w2.substr(0,minlen))return "";

            for(int j=0;j<minlen;j++){
                if(w1[j]!=w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;
        for(auto x:indegree){
            if(x.second==0)q.push(x.first);
        }
        string res;
        while(!q.empty()){
            char ch=q.front();
            q.pop();
            res.push_back(ch);
            for(auto x:adj[ch]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        return res.size()==indegree.size()?res:"";
    }
};
