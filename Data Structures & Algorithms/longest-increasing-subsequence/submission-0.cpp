class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0] = {1, 0};

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) dp[i][0] = max(dp[i][0], dp[j][0]);
            }
            dp[i][0] += 1;
        }

        int res = 1;
        for(int i = 0; i < n; i++) res = max(res, dp[i][0]);

        return res;

    }
};
