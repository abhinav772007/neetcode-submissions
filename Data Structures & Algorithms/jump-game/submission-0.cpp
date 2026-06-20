class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        //vector<bool> check(n,false);
        //check[n-1]=true;
        int temp=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=temp)temp=i;
        }
        return temp==0;
    }
};
