class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int ct=0;
        for(int j=0;j<chars.size();j++){
           char dum=chars[j];
            while(j<chars.size() && chars[j]==dum){
                ct++;
                j++;}
                j--;
                int temp=ct;
                ct=0;
                chars[i++]=dum;
                if(temp>1){
                string con=to_string(temp);
                for(auto c:con){
                    
                    chars[i]=c;
                    i++;
                }}
        }
        return i;
    }
};