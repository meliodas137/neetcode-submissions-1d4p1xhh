class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for(int i = 0; i < n; i++) {
            if(s[i] != '0') {
                dp[i+1] = dp[i];
                if(i > 0) {
                    if(s[i-1] == '1') {
                        dp[i+1] += dp[i-1];
                    }
                    else if(s[i-1] == '2' && s[i] <= '6' && s[i] >= '1') {
                        dp[i+1] += dp[i-1];
                    }
                }
            }
            else {
                if(i > 0) {
                    if(s[i-1] < '3' && s[i-1] >= '1') {
                        dp[i+1] = dp[i-1];
                    }
                    else dp[i+1] = 0;
                }
                else return 0;
            }
        }

        return dp[n];
    }
};
