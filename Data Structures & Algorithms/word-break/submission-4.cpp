class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dict;
        int sz = s.size();
        vector<int> dp(sz, -1);
        for(auto &w: wordDict) dict[w] = 1;

        return wordB(s, dict, dp, sz-1);
    }

    bool wordB(string s, unordered_map<string, int>& dict, vector<int> &dp, int y) {
        if(dp[y] != -1) return dp[y];

        if(dict.find(s) != dict.end()) {
            dp[y] = 1;
            return true;
        }

        for(int i = 0; i <= y; i++) {
            auto s1 = s.substr(i, y + 1 - i);
            auto s2 = s.substr(0, i);
            if(dict.find(s1) != dict.end() && wordB(s2, dict, dp, i)) {
                dp[y] = 1;
                return true;
            } 
        }

        dp[y] = 0;
        return false;
    }
};
