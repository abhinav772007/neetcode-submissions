class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
      
        stack<int> st;
        int n=temp.size();
         vector<int> out(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temp[st.top()]<=temp[i])st.pop();
            if(st.empty())out[i]=0;
            else out[i]=st.top()-i;
            st.push(i);
        }
        return out;
    }
};
