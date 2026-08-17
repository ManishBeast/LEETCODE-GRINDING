class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;
    int ans(int l ,int r){
        if(l==r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int res=0;
        for(int i=l;i<r;i++){
            int leftSum =prefix[i+1]-prefix[l]; // as prefix is 1 indexed biroooo
            int rightSum = prefix[r+1]-prefix[i+1];
             if (leftSum < rightSum) {
                res = max(res, leftSum + ans(l, i));
            }
            else if (leftSum > rightSum) {
                res = max(res, rightSum + ans(i + 1, r));
            }
            else {
                res = max(res, leftSum + max(ans(l, i),
                                             ans(i + 1, r)));
            }
        }
        return dp[l][r]= res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        prefix.resize(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i]+stoneValue[i];
        }
        return ans(0,n-1);
    }
};