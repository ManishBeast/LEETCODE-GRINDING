class Solution {
public:
    int ans(vector<int>&nums,int l,int r,vector<vector<int>> &dp){
        if(l>=r){
            return nums[l];
        }
        if(dp[l][r]!=-1) return dp[l][r];
       int firstScore = nums[l]-ans(nums,l+1,r,dp);
        int SecondScore = nums[r]-ans(nums,l,r-1,dp);
        return dp[l][r] = max(firstScore,SecondScore);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return ans(nums,0,n-1,dp)>=0;
    }
};