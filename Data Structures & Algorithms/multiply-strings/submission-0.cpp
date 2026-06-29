class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        vector<int> res(num1.length()+num2.length(),0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num1.length();i++){
            for(int j=0;j<num2.length();j++){
                int idg=(num1[i]-'0')*(num2[j]-'0');
                res[i+j]+=idg;
                res[i+j+1]+=(res[i+j]/10);
                res[i+j]%=10;
            }
        }
        stringstream out;
        int i=res.size()-1;
        while(i>=0 && res[i]==0)i--;
        while(i>=0){
            out<<res[i--];
        }
        return out.str();
    }
};
