class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left =0;
        int right =0;
        int n = nums.size();
        int maxi = INT_MIN;
        int sum =0;
        while(right<n){
            sum+=nums[right];
            maxi = max(maxi,sum);
            if(sum<0){
                sum = 0;
            }
            right++;
        }
        return maxi;
    }
};