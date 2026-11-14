class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+l-1; j < nums.size() && j < i+r; j++) {
                int sum = prefix[j];
                if (i > 0) sum -= prefix[i-1];

                if (sum > 0) ans = min(ans, sum);
            }
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};