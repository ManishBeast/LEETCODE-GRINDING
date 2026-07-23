class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int temp=0;
        int n = prices.size();

        for(int i=0;i<prices.size()-1;i++){
            int start = prices[i];
            while(i+1<n && prices[i]<prices[i+1]){
                i++;
            }
            int end = prices[i];
            if (end > start)
                temp += end - start;
        }
        return temp;
    }
};

