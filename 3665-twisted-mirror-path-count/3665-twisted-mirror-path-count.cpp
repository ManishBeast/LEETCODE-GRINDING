class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int mod = 1e9 + 7;
        vector<vector<long long>> R(n + 1, vector<long long>(m + 1, 0));
        vector<vector<long long>> D(n + 1, vector<long long>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    long long w = (i == 0 && j == 0) ? 1 : (R[i][j] + D[i][j]) % mod;
                    if (!w) continue;
                    if (j + 1 < m) R[i][j + 1] = (R[i][j + 1] + w) % mod;
                    if (i + 1 < n) D[i + 1][j] = (D[i + 1][j] + w) % mod;
                } else {
                    if (i + 1 < n) D[i + 1][j] = (D[i + 1][j] + R[i][j]) % mod;  
                    if (j + 1 < m) R[i][j + 1] = (R[i][j + 1] + D[i][j]) % mod; 
                }
            }
        }
        return (R[n - 1][m - 1] + D[n - 1][m - 1]) % mod;
    }
};