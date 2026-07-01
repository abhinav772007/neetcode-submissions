class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> j;
        int n=position.size();
        for(int i=0;i<n;i++){
            j.push_back({position[i],(double)(target-position[i])/speed[i]});
        }
        sort(j.rbegin(),j.rend());
        vector<double> st;
        for(auto x:j){
            st.push_back(x.second);
            if(st.size()>=2 && st.back()<=st[st.size()-2])st.pop_back();
        }
        return st.size();
    }
};
