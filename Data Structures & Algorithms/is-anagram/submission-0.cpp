class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> dict(26,0);
        for(int i = 0; i < s.size(); i++) {
            int idx1 = s[i]-'a';
            int idx2 = t[i]-'a';
            dict[idx1]++;
            dict[idx2]--;
        }

        for(auto &x:dict)
            if(x != 0) return false;

        return true;
    }
};
