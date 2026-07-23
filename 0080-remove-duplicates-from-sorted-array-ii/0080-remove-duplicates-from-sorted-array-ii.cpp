class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int helper =-1;
        int count =1;
        int j =0;
        for(int i=0;i<nums.size();i++){

            if(helper!=nums[i]){
                nums[j++] = nums[i];
                helper= nums[i]; 
                count=1;
            }else if(helper==nums[i] && count<2){
                nums[j++]= nums[i];
                count++;
            }
        }
        return j;
    }
};