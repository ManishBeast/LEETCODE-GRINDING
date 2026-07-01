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
            sum+= nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            cnt = cnt+(right-left+1);
            right++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return ans(nums,goal)-ans(nums,goal-1);
    }
};