class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)return 0;
        if(n==0)return 1;
        double out=1;
        long pow=abs((long)n);
        while(pow){
            if(pow&1){
                out*=x;
            }
            x*=x;
            pow=pow>>1;
        }
        return n>=0?out:1/out;
    }
};
