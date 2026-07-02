class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long dp0 = -1e18;

        long long dp1_m = -1e18;
        long long dp2_m = -1e18; //// chat gpt code bro u didn't did 

        long long dp1_d = -1e18;
        long long dp2_d = -1e18;
        
        long long max_sum = -1e18;

        for (long long x : nums) {
            long long v_mul = x * k;
            long long v_div = x / k; 

            long long next_dp0 = max(x, dp0 + x);

            long long next_dp1_m = max({v_mul, dp0 + v_mul, dp1_m + v_mul});
            long long next_dp2_m = max(dp1_m + x, dp2_m + x);
  
            long long next_dp1_d = max({v_div, dp0 + v_div, dp1_d + v_div});
            long long next_dp2_d = max(dp1_d + x, dp2_d + x);

            dp0 = next_dp0;
            dp1_m = next_dp1_m;
            dp2_m = next_dp2_m;
            dp1_d = next_dp1_d;
            dp2_d = next_dp2_d;

            max_sum = max({max_sum, dp1_m, dp2_m, dp1_d, dp2_d});
        }

        return max_sum;
    }
};