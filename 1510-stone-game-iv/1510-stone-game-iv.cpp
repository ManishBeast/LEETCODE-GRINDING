class Solution {
public:
    vector<int> dp;
    bool ans(int n){
        if(n==0){
            return false;
        }
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            if(ans(n-i*i)==false) 
                return dp[n]=true;
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        return ans(n);
    }
};