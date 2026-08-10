class Solution {
public:
    int n ;
    vector<vector<int>> dp;
    vector<int> suffix;
    int solve(int i,int M){
        if(i+2*M>=n){
            return suffix[i];
        }
        int maxim=0;
        if(dp[i][M]!=-1) return dp[i][M];
        for(int k=1;k<=2*M;k++){
            int maxi = max(k,M);
            int curr = suffix[i]-solve(i+k,maxi);
            maxim = max(maxim,curr);
        }
        return dp[i][M] = maxim;
    }
    int stoneGameII(vector<int>& piles) {
         n = piles.size();
         suffix.resize(n);
         dp.assign(n+1,vector<int>(n+1,-1));
         suffix[n-1]=piles[n-1];
         for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]+piles[i];
         }
         return solve(0,1);
    }
};