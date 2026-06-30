class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        // int n=arr.size();
        // vector<int> lef(n),rig(n);
        // stack<int> st;
        // for(int i=0;i<n;i++){
        //     while(!st.empty() && arr[st.top()]>arr[i])st.pop();
        //     lef[i]=st.empty()?i+1:i-st.top();
        //     st.push(i);
        // }
        // while(!st.empty())st.pop();
        // for(int i=n-1;i>=0;i--){
        //     while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        //     rig[i]=st.empty()?n-i:st.top()-i;
        //     st.push(i);
        // }
        // long long ans=0;
        // for(int i=0;i<n;i++){
        //     ans=max(ans,1LL*arr[i]*(lef[i]+rig[i]-1));
        // }
        // return (int)ans;
        int out=0;
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int ele=arr[st.top()];
                st.pop();
                int nse=i;
                int pse=(st.empty())?-1:st.top();
                out=max(out,ele*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele=arr[st.top()];
            st.pop();
            int nse=n;
            int pse=(st.empty())?-1:st.top();
            out=max(out,ele*(nse-pse-1));
        }
        return out;
    }
};