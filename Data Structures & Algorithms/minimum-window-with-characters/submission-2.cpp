class Solution {
public:
    string minWindow(string s, string t) {
        int sz1 = s.size(), sz2 = t.size();

        if(sz2 > sz1) return "";

        int i = 0, j = 0;

        int ri = 0, rj = 0;

        int res = INT_MAX;

        unordered_map<char,int> us, ut;

        for(auto &ch: t) ut[ch]++;


        while(i < sz1 && j < sz1) {
            char ch = s[j];
            us[ch]++;
            if(us[ch] <= ut[ch] && ut[ch] != 0) sz2--;

            if(sz2 == 0 && res > j-i+1) {
                ri = i;
                rj = j;
                res = j-i+1;
        cout<<ri<<' '<<rj<<'\n';
            }

            if(sz2 == 0) {
                while(i<j && us[s[i]] > ut[s[i]]) {
                    us[s[i]]--;
                    i++;
                }
                if(ut[s[i]] != 0) {
                    sz2++;
                    us[s[i]]--;
                    i++;
                }
            }
            j++;
            while(ut[s[i]] == 0 && i < j) { us[s[i]]--; i++;}
            while(ut[s[i]] < us[s[i]] && i < j) { us[s[i]]--; i++;}
        }
        if(res == INT_MAX) return "";
        return s.substr(ri, (rj-ri+1));
    }
};
