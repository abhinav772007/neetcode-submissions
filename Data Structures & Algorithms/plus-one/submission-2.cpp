class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       
        int n=digits.size();
        // vector<int> out(n+1,0);
        int carry=0;
        digits[n-1]+=1;
        int i=n;
        while(i>=1){
        digits[i-1]+=(carry);
        if(digits[i-1]<=9){
            //digits[n-1]+=1;
            return digits;
        }
        
        carry=1;
        digits[i-1]-=10;
        i--;
        }
        digits.insert(digits.begin(),1);
        return digits;

    }
};
