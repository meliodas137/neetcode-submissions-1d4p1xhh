class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n < 2) return n;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) dp[i][i] = 1;
        int count = n;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] == 1 || j <= i) continue;

                if(s[i] == s[j]){ 
                    if(j-1 < i+1) dp[i][j] = 1;
                    else dp[i][j] = dp[i+1][j-1];
                }
                else dp[i][j] = -1;

                if(dp[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;        
    }
}
;