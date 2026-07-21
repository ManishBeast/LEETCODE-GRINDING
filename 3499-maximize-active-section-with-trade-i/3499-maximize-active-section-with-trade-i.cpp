class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int i =0;
        int prevSum =-1;
        int maxSum=0;
        int ones=0;
        while(i<n){
            if(s[i]=='1'){
                ones++;
                i++;
            }else{
                int curr=0;
                while(i<n && s[i]=='0'){
                    i++;
                    curr++;
                }
                if(prevSum>0){
                    maxSum = max(maxSum,curr+prevSum);
                }
                prevSum = curr;
            }
        }
        return ones+maxSum;
    }
};