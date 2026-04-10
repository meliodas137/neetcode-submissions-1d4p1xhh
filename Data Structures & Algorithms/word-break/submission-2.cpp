class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dict;
        int sz = s.size();
        vector<vector<int>> dp(sz, vector<int>(sz, -1));
        for(auto &w: wordDict) dict[w] = 1;

        return wordB(s, dict, dp, 0, sz-1);
    }

    bool wordB(string s, unordered_map<string, int>& dict, vector<vector<int>> &dp, int x, int y) {
        if(dp[x][y] != -1) return dp[x][y];

        if(dict.find(s) != dict.end()) {
            dp[x][y] = 1;
            return true;
        }

        for(int i = x; i <= y; i++) {
            auto s1 = s.substr(i, y + 1 - i);
            auto s2 = s.substr(0, i);
            if(dict.find(s1) != dict.end() && wordB(s2, dict, dp, 0, i)) {
                dp[x][y] = 1;
                return true;
            } 
        }

        dp[x][y] = 0;
        return false;
    }
};
