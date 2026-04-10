class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1) return nums.front();

        vector<int> dp(sz + 1, 0);
        dp[1] = nums[0];
        dp[2] = max(dp[1], nums[1]);

        for(int i = 3; i <= sz; i++) {
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
        }

        return max(dp[sz], dp[sz-1]);

    }
};
