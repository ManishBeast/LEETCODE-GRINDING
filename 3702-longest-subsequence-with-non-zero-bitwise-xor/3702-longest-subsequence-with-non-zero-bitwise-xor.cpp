class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr = 0;
        for (int x : nums)
            xorr ^= x;
        if (xorr != 0)
            return nums.size();
        for (int x : nums) {
            if (x != 0)
                return nums.size() - 1;
        }
        
        return 0;
    }
};