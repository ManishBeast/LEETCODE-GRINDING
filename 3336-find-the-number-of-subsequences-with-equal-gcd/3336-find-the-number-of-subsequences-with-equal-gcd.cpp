class Solution {
public:
    int mod =1e9+7;
    vector<vector<vector<int>>> dp;
    int subs(vector<int>&nums,int idx,int g1,int g2){
        if(idx==nums.size()){
            return g1!=0 && g1==g2; // as hmlog 0 se intialise kr rhe h but hme g1 ==0 and. g2==0 ke liye solve thode krna h 
        }
        if(dp[idx][g1][g2]!=-1) return dp[idx][g1][g2];
        long long ans =0;
        ans+=subs(nums,idx+1,gcd(g1,nums[idx]),g2);
        ans+=subs(nums,idx+1,g1,gcd(g2,nums[idx]));
        ans+=subs(nums,idx+1,g1,g2);
        return dp[idx][g1][g2] = ans%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int m = *max_element(nums.begin(),nums.end());
        dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return subs(nums,0,0,0);
    }
};