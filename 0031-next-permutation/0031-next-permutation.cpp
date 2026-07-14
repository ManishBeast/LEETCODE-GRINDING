class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int left = n-2;
        while(left>=0 && nums[left]>=nums[left+1]){
            left--;
        }
        if(left<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int right = n-1;
        while(right>=0 && nums[right]<=nums[left]){
            right--;
        }
        swap(nums[left],nums[right]);
        reverse(nums.begin()+left+1,nums.end());
    }
};