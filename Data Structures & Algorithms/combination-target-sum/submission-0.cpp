class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<vector<int>> dp(sz + 1, vector<int>(target + 1, 0));
        sort(nums.begin(), nums.end());

        for(int i = 1; i <= sz; i++) dp[i][0] = 1;
        for(int j = 1; j <= target; j++) dp[0][j] = 0;
        dp[0][0] = 1;

        for(int i = 1; i <= sz; i++) {
            for(int j = 1; j <= target; j++) {
                if(j >= nums[i - 1])
                    dp[i][j] = max(dp[i][j], dp[i][j-nums[i-1]]);
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
            }
        }

        for(auto &v: dp) {
            for (auto &v1: v) cout<<v1<<", ";
            cout<<endl;
        }
        vector<vector<int>> res = collectRes(dp, nums, sz, target);

        return res;
    }

    vector<vector<int>> collectRes(vector<vector<int>> &dp, vector<int> &nums, int i, int j) {
        if(j < 0 || i < 0 || dp[i][j] == 0) return {};
        if(i == 0 && j == 0) return {{}};

        vector<vector<int>> res1, res2, res;
        if(dp[i-1][j] == 1) res1 = collectRes(dp, nums, i - 1, j);
        if(j >= nums[i - 1] && dp[i][j - nums[i - 1]] == 1) res2 = collectRes(dp, nums, i, j - nums[i - 1]);

        for(auto &v: res1) res.emplace_back(v);
        for(auto &v: res2) {
            v.emplace_back(nums[i -1]);
            res.emplace_back(v);
        }

        return res;
    }
};
