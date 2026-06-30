class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        vector<int> s11(26,0),s22(26,0);
        for(int i=0;i<s1.size();i++){
            s11[s1[i]-'a']++;
            s22[s2[i]-'a']++;
        }
        int ct=0;
        for(int i=0;i<26;i++){
            if(s11[i]==s22[i])ct++;
        }
        int l=0;
        for(int i=s1.size();i<s2.size();i++){
            if(ct==26)return true;
            int ind=s2[i]-'a';
            s22[ind]++;
            if(s11[ind]==s22[ind])ct++;
            else if(s11[ind]+1==s22[ind])ct--;
            ind=s2[l]-'a';
            s22[ind]--;
            if(s11[ind]==s22[ind])ct++;
            else if(s11[ind]-1==s22[ind])ct--;
            l++;
        }
        return ct==26;


    }
};
