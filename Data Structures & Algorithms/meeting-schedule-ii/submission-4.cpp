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
        priority_queue<int, vector<int>, greater<int>> minh;
        sort(intervals.begin(), intervals.end(), []
        (const Interval &a, const Interval &b) {
            return a.start < b.start;
        });
        for(int i = 0; i < intervals.size(); i++) {
            if(!minh.empty() && minh.top() <= intervals[i].start) {
                minh.pop();
            }
            minh.push(intervals[i].end);
        }
        return minh.size();
    }
};
