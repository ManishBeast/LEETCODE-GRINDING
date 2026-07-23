class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            int  k = prices[i]-mini;
            mini = min(mini,prices[i]);
            ans = max(ans,k);
        }
        return ans;
    }
};