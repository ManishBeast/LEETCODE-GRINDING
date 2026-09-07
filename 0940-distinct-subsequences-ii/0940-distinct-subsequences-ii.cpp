class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (s[j] != s[i]) {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};