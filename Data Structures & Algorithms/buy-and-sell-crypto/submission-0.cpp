class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int currMin = prices[0];
        int res = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > currMin) res = max(res, prices[i] - currMin);
            else currMin = min(currMin, prices[i]);
        }

        return res;
    }
};
