class Solution {
public:

    int calcK(vector<int> &dict){
        int m = 0, s = 0;

        for(auto &n : dict) {
            m = max(m, n);
            s += n;
        }

        return (s-m);
    }

    int characterReplacement(string s, int k) {
        int sz = s.size();

        if(sz < 2 || k == sz - 1 || k == sz) return sz;

        vector<int> dict(26, 0);

        int i = 0, j = 0, res = 0;

        while (i < sz) {
            while (j < sz) {
                dict[s[j] - 'A']++;
                int tempK = calcK(dict);

                while (tempK > k && i < j) {
                    dict[s[i] - 'A']--;
                    i++;
                    tempK = calcK(dict);
                }
                res = max(res, j-i+1);
                j++;
            }
            i++;
        }

        return res;
    }
};
