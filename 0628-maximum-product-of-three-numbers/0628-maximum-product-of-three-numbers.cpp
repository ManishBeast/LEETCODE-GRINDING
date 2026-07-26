class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = INT_MIN;
        int n = nums.size();
        int k = nums[0]*nums[1]*nums[n-1];
        int k1 = nums[0]*nums[n-2]*nums[n-1];
        int k2 = nums[n-2]*nums[n-3]*nums[n-1];
        return max(k,max(k1,k2));
    }
};