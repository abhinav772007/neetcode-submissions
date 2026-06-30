class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int out=0,l=0;
        int maxf=0;
        vector<int> h(26,0);
        for(int i=0;i<n;i++){
            h[s[i]-'A']++;
            maxf=max(maxf,h[s[i]-'A']);
            while((i-l+1)-maxf>k){
                h[s[l]-'A']--;
                maxf=0;
                for(int j=0;j<26;j++)maxf=max(maxf,h[j]);
                l++;
            }
            out=max(out,i-l+1);
        }
        return out;
    }
};
