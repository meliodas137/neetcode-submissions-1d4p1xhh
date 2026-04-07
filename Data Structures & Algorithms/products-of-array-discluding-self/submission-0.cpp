class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> output(sz, 1), before(sz+1, 1), after(sz+1, 1);

        for(int i = 0; i < sz; i++) {
            before[i+1] = before[i]*nums[i];
            after[sz-i-1] = after[sz-i]*nums[sz-i-1]; 
        }

        for(int i = 0; i < sz; i++) {
            output[i] = before[i]*after[i+1];
        }

        return output;
    }
};
