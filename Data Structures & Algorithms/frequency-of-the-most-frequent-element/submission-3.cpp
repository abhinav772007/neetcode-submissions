class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int siz=1,l=0,cur=0;
        for(int i=1;i<nums.size();i++){
            cur+=(i-l)*(nums[i]-nums[i-1]);
            if(cur>k){
                cur-=(nums[i]-nums[l]);
                l++;
            }

            siz=max(siz,i-l+1);
        }
        return siz;
    }
};