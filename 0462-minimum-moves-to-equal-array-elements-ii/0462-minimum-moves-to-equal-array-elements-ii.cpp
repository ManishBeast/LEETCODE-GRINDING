class Solution {
public:
    int solve(vector<int> &nums,int mid){
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=abs(nums[i]-mid);
        }
        return sum;
    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid = nums[n/2];
        return solve(nums,mid);
    }
};