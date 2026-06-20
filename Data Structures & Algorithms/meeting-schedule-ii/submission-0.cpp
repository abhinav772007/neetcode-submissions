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
    int minMeetingRooms(vector<Interval>& intervals) {
         vector<pair<int,int>> inn;
        for(auto x:intervals){
            int a=x.start,b=x.end;
            inn.push_back({a,b});
        }
        int maxi=0;
        for(auto x:inn){
            maxi=max(maxi,x.second);
        }
        int n=inn.size();
        vector<int> ct(maxi+1,0);
        int rooms=0,res=0;
        for(int i=0;i<n;i++){
            ct[inn[i].first]++;
            ct[inn[i].second]--;
        }
        for(int i=0;i<=maxi;i++){
            rooms+=ct[i];
            res=max(res,rooms);
        }
        return res;
    }
};
