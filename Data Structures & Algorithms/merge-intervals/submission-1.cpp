class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> line, res;

        for(auto &i: intervals){
            line.emplace_back(vector<int>{i[0], 0});
            line.emplace_back(vector<int>{i[1], 1});
        }

        sort(line.begin(), line.end());

        int s = -1, e = -1, c = 0;
        for(auto &p: line){
            if(p[1] == 0) {
                c++;
                if(c == 1) s = p[0];
            }
            else {
                c--;
                if(c == 0) res.emplace_back(vector<int>{s, p[0]});
            }
        }

        return res;
    }
};
