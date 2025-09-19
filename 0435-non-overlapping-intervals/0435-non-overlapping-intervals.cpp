bool comp(vector<int>& a1 , vector<int>& a2){
    return a1[1] < a2[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int endTime = intervals[0][1];
        int cnt=1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=endTime){
                cnt++;
                endTime = intervals[i][1];
            }
        }

        return intervals.size()-cnt;
    }
};