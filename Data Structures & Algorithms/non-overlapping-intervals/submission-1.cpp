class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int remove = 0;
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= prevEnd) {
                prevEnd = intervals[i][1];
            }
            else {
                remove++;
                prevEnd = min(intervals[i][1], prevEnd);
            }
        }
        return remove;
    }
};
