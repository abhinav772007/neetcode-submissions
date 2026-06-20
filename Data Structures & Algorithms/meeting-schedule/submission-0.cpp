/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,int>> inn;
        for(auto x:intervals){
            int a=x.start,b=x.end;
            inn.push_back({a,b});
        }
        sort(inn.begin(),inn.end());
        int n=inn.size();
        int end=inn[0].second;
        for(int i=1;i<n;i++){
            if(end>inn[i].first)return false;
            end=inn[i].second;
        }
        return true;
    }
};
