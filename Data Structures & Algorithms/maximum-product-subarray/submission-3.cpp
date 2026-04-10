class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> pdp(n, (vector<int>(n, 1)));
        vector<vector<int>> ndp(n, (vector<int>(n, -1)));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    pdp[i][j] = nums[j];
                    ndp[i][j] = nums[j];
                }
                if(i >= j) continue;

                pdp[i][j] = nums[j] > 0 ? max(1, pdp[i][j-1])*nums[j] : max(ndp[i][j-1]*nums[j], nums[j]);
                ndp[i][j] = nums[j] > 0 ? min(1, ndp[i][j-1])*nums[j] : min(nums[j], pdp[i][j-1]*nums[j]);
            }
        }

        int res = pdp[0][0];
        for(int i = 1; i < n; i++) res = max(res, pdp[0][i]);
        return res;
    }
};
