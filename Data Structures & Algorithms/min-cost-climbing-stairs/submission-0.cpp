class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x=0,y=0;
        for(int i=2;i<=cost.size();i++){
            int temp=y;
            y=min(y+cost[i-1],x+cost[i-2]);
            x=temp;
        }
        return y;
    }
};
