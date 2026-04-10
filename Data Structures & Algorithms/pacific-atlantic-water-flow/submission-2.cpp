class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int x = heights.size(), y = heights[0].size();

        vector<vector<int>> pdp(x, vector<int>(y, 0)), adp(x, vector<int>(y, 0));
        for(int i = 0; i < x; i++) {
            pdp[i][0] = 1;
            adp[i][y-1] = 1;
        }

        for(int i = 0; i < y; i++) {
            pdp[0][i] = 1;
            adp[x-1][i] = 1;
        }
        vector<vector<int>> res;

        for(int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if(adp[i][j] == 0) fill(adp, heights, i, j, x, y);
                if(pdp[i][j] == 0) fill(pdp, heights, i, j, x, y);
                if(adp[i][j] == pdp[i][j] && adp[i][j] == 1) res.push_back({i, j});
            }
        }

        return res;

    }

    void fill(vector<vector<int>> &dp, vector<vector<int>>& h, int i, int j, int x, int y) {
        if(i < 0 || j < 0 || i >= x || j >= y) return;
        if(dp[i][j] != 0) return;

        dp[i][j] = -1;
        if(dp[i][j] != 1 && i > 0 && h[i][j] >= h[i-1][j]) {
            fill(dp, h, i-1, j, x, y);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
        if(dp[i][j] != 1 && j > 0 && h[i][j] >= h[i][j-1]) {
            fill(dp, h, i, j-1, x, y);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
        if(dp[i][j] != 1 && i < x - 1 && h[i][j] >= h[i+1][j]) {
            fill(dp, h, i+1, j, x, y);
            dp[i][j] = max(dp[i][j], dp[i+1][j]);
        }
        if(dp[i][j] != 1 && j < y - 1 && h[i][j] >= h[i][j+1]) {
            fill(dp, h, i, j+1, x, y);
            dp[i][j] = max(dp[i][j], dp[i][j+1]);
        }
        return;
    }
};
