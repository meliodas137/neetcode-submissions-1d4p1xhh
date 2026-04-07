class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<pair<int,int>> dict;
        for(int k = 0; k < nums.size(); k++) {
            dict.emplace_back(make_pair(nums[k], k));
        } 
        sort(dict.begin(), dict.end(), [](pair<int,int> a, pair<int,int>b) { return (a.first < b.first); });

        while(i < j) {
            if(dict[i].first + dict[j].first == target) return {min(dict[i].second, dict[j].second), max(dict[i].second, dict[j].second)};
            if(dict[i].first + dict[j].first < target) i++;
            else j--;
        }

        return {0,0};
    }
};
