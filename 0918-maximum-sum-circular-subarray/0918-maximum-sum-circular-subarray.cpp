class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum =nums[0];
        int currMaxSum =0;
        int minSum =nums[0];
        int currMinSum =0;
        int total =0;
        for(auto x:nums){
            currMaxSum = max(x,currMaxSum+x);
            maxSum = max(maxSum,currMaxSum);
            currMinSum = min(x,currMinSum+x);
            minSum = min(minSum,currMinSum);
            total+=x;
        }
        if(maxSum<0){
            return maxSum;
        }
        return max(maxSum,total-minSum);
    }
};