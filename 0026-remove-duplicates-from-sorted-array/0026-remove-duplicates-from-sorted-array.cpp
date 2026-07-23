class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int helper =-200;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(helper!=nums[i]){
                nums[j++] = nums[i];
                helper = nums[i];
            }
        }
        return j;
    }
};