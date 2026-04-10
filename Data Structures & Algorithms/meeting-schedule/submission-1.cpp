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
        if(intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](Interval &i1, Interval &i2){
            return i1.start < i2.start;
        });

        for(int i = 0; i < intervals.size() - 1; i++) {
            if(intervals[i].end > intervals[i+1].start) return false;
        }

        return true;
    }
};
