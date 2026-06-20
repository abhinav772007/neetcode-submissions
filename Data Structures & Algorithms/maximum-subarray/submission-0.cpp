class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int out=INT_MIN,maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi+nums[i],nums[i]);
            out=max(out,maxi);
        }
        return out;
    }
};
