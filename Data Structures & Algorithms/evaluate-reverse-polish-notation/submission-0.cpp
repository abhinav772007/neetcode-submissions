class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> st;
      for(auto x:tokens){
        if(x=="+" || x=="-" || x=="/" || x=="*"){
          int z=st.top();
          st.pop();
          int y=st.top();
          st.pop();
          if(x=="+")st.push(z+y);
          else if(x=="-")st.push(y-z);
          else if(x=="*")st.push(y*z);
          else st.push(y/z);
        }
        else st.push(stoi(x));
      }
      return st.top();
    }
};
