class Solution {
public:
    int ans(vector<int> & nums,int i ,vector<int> &dp){
        int n = nums.size();
        if(i>=n){
            return 0;
        }
        int temp=0;
        int maxi =INT_MIN;
        if(dp[i]!=-1) return dp[i];
        for(int k=1;k<=3 && i+k<=n ;k++){
            temp+= nums[i+k-1];
            maxi = max(maxi,temp-ans(nums,i+k,dp));
        }
        return dp[i] = maxi;

    }
    string stoneGameIII(vector<int>& stoneValue) {
         int n= stoneValue.size();
         vector<int> dp(n,-1);

         int j = ans(stoneValue,0,dp);
         string s = "";
         if(j>0){
            s +="Alice";
         }else if(j<0){
            s+="Bob";
         }else{
            s+="Tie";
         }
         return s;
    }
};