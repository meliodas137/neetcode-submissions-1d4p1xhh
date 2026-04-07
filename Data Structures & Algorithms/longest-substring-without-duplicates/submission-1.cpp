class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) return s.size();
        vector<int> dict(256, 0);

        int i = 0, temp = 1, j = 1;
        dict[s[0]] = 1;
        int res = 1;
        while(i < s.size()) {
            while(j < s.size()) {
                if(dict[s[j]] == 0) {
                    temp++;
                    dict[s[j]]++;
                    j++;
                }
                else {
                    res = max(res, temp);
                    while(i < j && s[i] != s[j]) {
                        dict[s[i]]--;
                        i++;
                        temp--;
                    }
                    dict[s[i]]--;
                    i++;
                    temp--;
                }
            }
            res = max(res, temp);
            dict[s[i]]--;
            i++;
            temp--;
        }

        return res;
    }
};
