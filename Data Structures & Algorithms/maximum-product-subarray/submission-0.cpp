class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int out=nums[0],curmin=1,curmax=1;
       for(int x:nums){
        int temp=curmax*x;
        curmax=max(max(x*curmax,x*curmin),x);
        curmin=min(min(temp,x*curmin),x);
        out=max(out,curmax);
       }
       return out;
    }
};
