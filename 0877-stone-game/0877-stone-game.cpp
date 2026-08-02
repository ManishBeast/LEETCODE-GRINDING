class Solution {
public:
    vector<vector<int>> dp;
    int ans(vector<int> &piles,int l,int r){
        if(l==r){
            return piles[l];
        }
        if(dp[l][r]!=-1) return dp[l][r];
        int first =piles[l]-ans(piles,l+1,r);
        int second =piles[r]-ans(piles,l,r-1);
        return dp[l][r] = max(first,second);
    }
    bool stoneGame(vector<int>& piles) {
       int n = piles.size();
       dp.assign(n,vector<int>(n,-1));
       return ans(piles,0,n-1)>=0;
    }
};