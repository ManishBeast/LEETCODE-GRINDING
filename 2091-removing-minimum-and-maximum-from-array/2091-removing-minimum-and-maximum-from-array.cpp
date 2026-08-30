class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini =INT_MAX;
        int maxi =INT_MIN;
        int miniIdx=0;
        int maxiIdx=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi= nums[i];
                maxiIdx =i;
            }
            if(nums[i]<mini){
                mini = nums[i];
                miniIdx =i;
            }
        }
        if(nums.size()<=2) return nums.size();
        int one=0;
        int second =0;
        int third =0;
        if(miniIdx>maxiIdx){
            one = nums.size()-maxiIdx;
            second = miniIdx+1;
            third = nums.size()-miniIdx + maxiIdx+1;
        }else{
            one = nums.size()-miniIdx;
            second = maxiIdx+1;
            third = nums.size()-maxiIdx+miniIdx+1;
        }
        int ans = min(one,min(second,third));
        return ans;
    }
};