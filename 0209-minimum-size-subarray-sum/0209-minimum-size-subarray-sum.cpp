class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left =0;
        int right =0;
        int n = nums.size();
        int mini = INT_MAX;
        int sum =0;
        int count =0;
        while(right<n){
           
            sum+=nums[right];
            right++;
            count++;
             while(left<n && sum>=target){
                sum-=nums[left];
                left++;
                mini = min(mini,count);
                count--;
            }
            
        }
        return mini==INT_MAX?0:mini;
    }
};