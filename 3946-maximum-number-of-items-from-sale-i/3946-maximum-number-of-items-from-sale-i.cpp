class Solution {
public:

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int factors[1501];
        memset(factors , 0 , sizeof(factors));

        for (int i = 0 ; i < n ; i++) factors[items[i][0]]++;


        for (int i = 1 ; i < 1501 ; i++)
        {
            if (factors[i] == 0 ) continue;
            for (int j = 2 * i ; j < 1501 ; j+=i)
            {
                factors[i] += factors[j];
            }
        }

        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int p = items[i][1]; 
            int first = factors[items[i][0]];         
            for (int b = budget; b >= p; b--) {
                dp[b] = max(dp[b] , dp[b-p] + first);
            }
            for (int b = p ; b <= budget ; b++)
            {
                dp[b] = max(dp[b] , dp[b-p] + 1);
            }
        }
        return dp[budget];
    }
};