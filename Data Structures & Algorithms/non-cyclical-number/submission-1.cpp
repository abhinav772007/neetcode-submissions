class Solution {
public:
    int func(int x){
        int out=0;
        while(x){
            int temp=x%10;
            out=out+temp*temp;
            x/=10;
        }
        return out;
    }
    bool isHappy(int n) {
        // unordered_map<int,int> mp;
        // while(n!=1){
        //     int x=func(n);
        //     if(mp[x])return false;
        //     mp[x]=1;
        //     n=x;
        // }
        // return true;
        int slow=n,fast=func(n);
        while(slow!=fast){
            fast=func(fast);
            fast=func(fast);
            slow=func(slow);
        }
        return fast==1;
    }
};
