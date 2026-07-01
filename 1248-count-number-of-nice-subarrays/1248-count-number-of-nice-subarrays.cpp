class Solution {
public:
    int ans(vector<int>& nums, int goal){
        int maxLen =0;
        int sum =0;
        int n = nums.size();
        int left =0;
        int right =0;
        int cnt =0;
        if(goal<0) return 0;
        while(right<n){
            sum+= nums[right]%2;
            while(sum>goal){
                sum-=nums[left]%2;
                left++;
            }
            cnt = cnt+(right-left+1);
            right++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
         return ans(nums,k)-ans(nums,k-1);
    }
};