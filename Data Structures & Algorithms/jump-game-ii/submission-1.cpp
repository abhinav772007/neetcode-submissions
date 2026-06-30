// class Solution {
// public:
//     int jump(vector<int>& nums) {
//       int n=nums.size();
//     //  vector<int> dp(n,1e8);
//     //  dp[n-1]=0;
//     //  for(int i=n-2;i>=0;i--){
//     //    // int mini=INT_MAX;
//     //     int temp=min(n,nums[i]+i+1);
//     //     for(int j=i+1;j<temp;j++){
//     //         dp[i]=min(dp[i],1+dp[j]);
//     //     }
//     //  } 
//     //  return dp[0]; 
    


//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int r=0,l=0;
        int out=0;
        while(r<n-1){
            int far=0;
            for(int i=l;i<=r;i++){
                far=max(far,nums[i]+i);
            }
            l=r+1;
            r=far;
            out++;
        }
        return out;
    }
};