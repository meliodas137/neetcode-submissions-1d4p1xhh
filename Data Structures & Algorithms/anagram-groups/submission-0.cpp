class Solution {
public:

    int isAnagram(string s1, string s2) {
        if(s1.size() != s2.size()) return 0;
        vector<int> dict(26,0);
        for(int i = 0; i < s1.size(); i++) {
            int i1 = s1[i] - 'a';
            int i2 = s2[i] - 'a';
            dict[i1]++;
            dict[i2]--;
        }

        for(auto &x:dict){
            if(x != 0) return 0;
        }
        return 1;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() <= 1)
            return { strs };

        vector<vector<string>> res;

        for(auto &str: strs) {
            int grouped = 0;
            for(auto &grp: res) {
                if((grouped = isAnagram(grp[0], str)) == 1) {
                    grp.emplace_back(str);
                    break;
                }
            }
            if(grouped == 0) res.emplace_back(vector<string>{str});
        }

        return res;
    }
};
