class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {{}};
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        unordered_map<int, int> umap;

        for(auto &n: nums) {
            if(umap.find(n) == umap.end()) umap[n] = 0;
            umap[n]++;
        }
        int i = 0;
        while(i < nums.size() - 2) {
            int j = i+1;
            if(nums[i] + nums[j] > 0) break;

            while (j < nums.size() - 1) {
                if(nums[i] + nums[j] > 0) break;
                int temp = (-1)*(nums[i] + nums[j]);
                if(temp >= nums[j+1] && umap[temp] > 0) {
                    res.emplace_back(vector<int>{nums[i], nums[j], temp});
                }
                while(j < nums.size() - 1 && nums[j] == nums[j+1]) j++;
                j++;
            }
            
            while(i < nums.size() - 2 && nums[i] == nums[i+1]) i++;
            i++;
        }

        return res;
    }
};
