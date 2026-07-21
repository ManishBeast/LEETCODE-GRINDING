class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int prevSum =-1;
        int i=0;
        int n = s.size();
        int maxSum=0;
        int ones=0;
        while(i<n){
            if(s[i]=='1'){
                i++;
                ones++;
            }else{
                int curr=0;
                while(i<n && s[i]=='0'){
                    curr++;
                    i++;
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