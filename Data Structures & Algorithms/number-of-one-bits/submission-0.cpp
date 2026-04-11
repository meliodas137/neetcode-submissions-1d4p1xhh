class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n <= 1) return n;
        if((n >> 1) << 1 == n) return hammingWeight(n >> 1);
        return 1 + hammingWeight(n >> 1);
    }
};
