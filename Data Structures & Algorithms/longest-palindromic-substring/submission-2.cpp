class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) dp[i][i] = 1;
        int x = 0, y = 0;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] == 1 || j <= i) continue;

                if(s[i] == s[j]){ 
                    if(j-1 < i+1) dp[i][j] = 1;
                    else dp[i][j] = dp[i+1][j-1];
                }
                else dp[i][j] = -1;

                if(dp[i][j] == 1) {
                    if(j-i > y-x) {
                        x = i;
                        y = j;
                    }
                }
            }
        }

        return s.substr(x, y-x+1);
    }
};
