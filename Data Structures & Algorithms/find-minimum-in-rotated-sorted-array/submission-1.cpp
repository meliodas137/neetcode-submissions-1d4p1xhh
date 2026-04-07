class Solution {
public:
    int findMin(vector<int> &nums) {
        int sz = nums.size();
        if(sz == 1) return nums[0];

        int l = nums.front(), r = nums.back();

        int i = 0, j = sz - 1;

        while (i < j) {
            if (l < r)
            {
                return l;
            }
            else if (l > r)
            {
                int mid = (i+j+1)/2;

                if(nums[mid] > l) {
                    i = mid+1;
                    l = nums[mid+1];
                } else {
                    j = mid;
                    r = nums[mid];
                    i++;
                    l=nums[i];
                }
            }
        }

        return nums[i];
    }
};
