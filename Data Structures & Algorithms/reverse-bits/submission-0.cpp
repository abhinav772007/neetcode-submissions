class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t out=0;
        int mul=31;
        while(n){
            out+=((n&1)*1<<mul);
            n=n>>1;
            mul--;
        }
        return out;
    }
};
