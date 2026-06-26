class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out=0;
        for(int x:nums)out^=x;
        return out;
    }
};
