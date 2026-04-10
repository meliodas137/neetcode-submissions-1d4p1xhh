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
        vector<vector<int>> line;

        for(auto &i: intervals){
            line.emplace_back(vector<int>{i.start, 1});
            line.emplace_back(vector<int>{i.end, 0});
        }

        sort(line.begin(), line.end());

        int s, c = 0, res = 0;
        for(auto &p: line){
            if(p[1] == 1) {
                c++;
                if(c == 1) s = p[0];
            }
            else {
                c--;
            }
            res = max(res, c);
        }

        return res;
    }
};
