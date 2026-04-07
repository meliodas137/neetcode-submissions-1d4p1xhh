class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> dict;
        for(auto &n: nums) {
            dict[n] = 0;
        }

        int res = 0;

        for(auto &n: nums) {
            if(dict[n] == 0) {
                dict[n] = 1;
                int temp = 1;
                int f = n+1;
                int b = n-1;
                while(dict.find(b) != dict.end()) {
                    temp++;
                    dict[b] = 1;
                    b--;
                }

                while(dict.find(f) != dict.end()) {
                    temp++;
                    dict[f] = 1;
                    f++;
                }

                res = max(res, temp);
            }
        }

        return res;
    }
};
