class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums)sum+=x;
        //cout<<sum<<"\n";
        if((sum+target)%2!=0 || sum<target || target<-sum)return 0;
        int newtar=(sum+target)/2;
        vector<int> prev(newtar+1,0);
        if(nums[0]==0)prev[0]=2;
        else{
           prev[0]=1;
            if(nums[0]<=newtar)prev[nums[0]]=1;

        }
        //prev[0]++;
        for(int i=1;i<n;i++){
            for(int j=newtar;j>=0;j--){
                if(nums[i]<=j)prev[j]+=prev[j-nums[i]];
            }
        }
        return prev[newtar];

    }
};