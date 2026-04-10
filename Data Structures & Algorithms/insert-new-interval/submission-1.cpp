class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int start = newInterval[0], end = newInterval[1], pushed = 0;

        for(auto &i: intervals) {
            if(i[1] < newInterval[0]) res.emplace_back(i);
            if(i[1] >= newInterval[0] && i[0] <= newInterval[0]) start = i[0];
            if(i[0] <= newInterval[1] && i[1] >= newInterval[1]) end = i[1];
            if(i[0] > newInterval[1]) {
                if(pushed == 0) {
                    res.emplace_back(vector<int>{start, end});
                    pushed = 1;
                }
                res.emplace_back(i);
            }
        }
        if(pushed == 0) {
            res.emplace_back(vector<int>{start, end});
            pushed = 1;
        }

        return res;
    }
};
