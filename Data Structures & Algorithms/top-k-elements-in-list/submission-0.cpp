class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> temp;
        vector<pair<int,int>> res;
        for(auto &num:nums) {
            if(temp.find(num) == temp.end()) {
                temp[num] = 1;
            }
            else temp[num]++;
        }

        for(auto i: temp) {
            res.emplace_back(make_pair(i.second, i.first));
        }

        sort(res.begin(), res.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.first > b.first;
        });

        vector<int> ret;
        for( int i = 0; i < k; i++) ret.emplace_back(res[i].second);

        return ret;
    }
};
