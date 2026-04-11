class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = (n*(n+1))/2;

        for(auto &x: nums) s -= x;

        return s;
    }
};
