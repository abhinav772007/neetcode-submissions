class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> j;
        int n=position.size();
        for(int i=0;i<n;i++){
            j.push_back({position[i],(double)(target-position[i])/speed[i]});
        }
        sort(j.begin(),j.end());
        stack<double> st;
        st.push(j[n-1].second);
        for(int i=n-2;i>=0;i--){
            if(!st.empty() && st.top() < j[i].second )st.push(j[i].second);
            
        }
        int out=0;
        while(!st.empty()){
            out++;
            st.pop();
        }
        return out;
    }
};
