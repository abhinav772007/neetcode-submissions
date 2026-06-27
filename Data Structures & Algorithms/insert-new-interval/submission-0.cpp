class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> out;
        int st=newInterval[0],en=newInterval[1];
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(intervals[i][0]>en){
                out.push_back(newInterval);
                copy(intervals.begin()+i,intervals.end(),back_inserter(out));
                return out;
            }
            else if(intervals[i][1]<st){
                out.push_back(intervals[i]);
            }
            else{
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
                
            }
        }
        out.push_back(newInterval);
        return out;
    }
};
