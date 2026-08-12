class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mpp;
        int n = nums.size();
        int left =0;
        int right = 0;
        int maxi =0;
        while(right<n){
              mpp[nums[right]]++;
            while(mpp[nums[right]]>k){
                mpp[nums[left]]--;
                left++;
            }
    
            maxi = max(maxi,right-left+1);
            right++;
        }
        return maxi ;
    }
};