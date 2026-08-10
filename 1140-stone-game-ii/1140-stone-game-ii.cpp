class Solution {
private:
    vector<vector<int>> dp;
    vector<int> suffixSum;
    int n;

    int solve(int i, int M) {
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }

        if (dp[i][M] != -1) return dp[i][M];

        int maxStones = 0;

        for (int X = 1; X <= 2 * M; ++X) {
            int nextM = max(M, X);
            int currentStones = suffixSum[i] - solve(i + X, nextM);
            maxStones = max(maxStones, currentStones);
        }

        return dp[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffixSum.resize(n);
        dp.assign(n+1,vector<int>(n+1,-1));
        suffixSum[n-1] = piles[n-1];
        for(int i=n-2;i>=0;i--){
            suffixSum[i] = suffixSum[i+1]+piles[i];
        }

        return solve(0, 1);
    }
};