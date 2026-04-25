class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(auto &n: nums) s += n;
        if(s%2 == 1) return false;

        s /= 2;

        vector<int> dp(s + 1, 0);

        sort(nums.begin(), nums.end());
        dp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            // if(dp[s] == 1) return 1;
            if(nums[i] <= s) {
                for(int j = s; j >= 0; j--) {
                    if(j + nums[i] > s) continue; 
                    if(dp[j] == 1) dp[j + nums[i]] = 1;
                }
            }
        }

        for(auto &n : dp) cout<<n<<',';
        return dp[s];
    }
};
