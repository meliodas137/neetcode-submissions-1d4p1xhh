class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();

        int i = 0, j = sz - 1;

        while(i <= j) {
            int l = nums[i], r = nums[j];
            int mid = (i+j+1)/2;
            if(l == target) return i;
            if(r == target) return j;
            if(nums[mid] == target) return mid;

            if(l < r)
            {
                // if( l > target && r < target) return -1;
                // if( l > target && r > target) return -1;
                if(nums[mid] > target) {
                    j = mid-1;
                } else {
                    i = mid+1;
                }
            }
            else {
                // if(r > target && l < target) return -1;
                if(nums[mid] > target) {
                    if(l > nums[mid]) j = mid - 1;
                    else i = mid + 1;
                } 
                else {
                    if(r > target) i = mid + 1;
                    else j = mid - 1;
                } 
            }
        }
        if( i < sz && nums[i] == target) return i;
        if( j < sz && nums[j] == target) return j;
        return -1;
    }
};
