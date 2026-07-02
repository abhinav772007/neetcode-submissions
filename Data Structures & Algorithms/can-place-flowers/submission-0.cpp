class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ct=flowerbed[0]==0?1:0;
        for(int x:flowerbed){
            if(x==1){
                n-=(ct-1)/2;
                ct=0;
            }
            else ct++;
        }
        n-=ct/2;
        return n<=0;
    }
};