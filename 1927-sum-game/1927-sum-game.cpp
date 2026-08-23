class Solution {
public:
    bool sumGame(string num) {
        int leftSum = 0;
        int rightSum = 0;

        int leftQ=0;
        int rightQ=0;
        int n = num.size();
        for(int i=0;i<n;i++){
            if(i<n/2 && num[i]!='?'){
                leftSum+=num[i]-'0';
            }else if(i>=n/2 && num[i]!='?'){
                rightSum+=num[i]-'0';
            }
            if(i<n/2 && num[i]=='?'){
                leftQ++;
            }else if(i>=n/2 && num[i]=='?'){
                rightQ++;
            }
        }
        int change = rightQ-leftQ;
        if(change ==0) return leftSum!=rightSum;
        int changeSum = rightSum-leftSum;
         if (change% 2 != 0)
            return true;

        return changeSum != -9 * change / 2;

    }
};