class Solution {
public:
    int uniquePaths(int m, int n) {
      long long out=1;
        m--;
        n--;
        if(m<n)swap(m,n);
        for(long long i=0;i<n;i++){
            out=out*(m+1+i)/(i+1);
        }
        return (int)out;
    }
};
