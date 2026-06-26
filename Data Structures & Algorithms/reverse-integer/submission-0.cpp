class Solution {
public:
    int reverse(int x) {
       
        int out=0;

        while(x){
           int dig=x%10;
           x/=10;
           if(out>INT_MAX/10 || (out==INT_MAX/10 && dig>INT_MAX%10))return 0;
           if(out<INT_MIN/10 || (out==INT_MIN/10 && dig<INT_MIN%10))return 0;
           out=out*10+dig;
        }
       
        return (int)out;
    }
};
