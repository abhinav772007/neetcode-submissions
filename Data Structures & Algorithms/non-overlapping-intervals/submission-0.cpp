class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int out=0;
        int prev=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int sta=intervals[i][0],end=intervals[i][1];
            if(sta>=prev){
                prev=end;
            }
            else{
                out++;
                prev=min(prev,end);
            }
        }
        return out;
    }
};
