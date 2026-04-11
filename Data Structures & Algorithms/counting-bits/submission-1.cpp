class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);

        int i = 1;
        while(i <= n) {res[i] = 1; i *= 2;}

        for(i = 3; i <= n; i++) {
            if(res[i] != 0) continue;

            res[i] = res[(i >> 1)];
            if(i%2 == 1) res[i]++;
        }

        return res;
    }
};
