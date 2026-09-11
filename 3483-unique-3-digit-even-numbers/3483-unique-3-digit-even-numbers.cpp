class Solution {
public:
    
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> digit(10,0);
        int ans =0;
        for(auto x:digits){
            digit[x]++;
        }
        for(int i=1;i<=9;i++){
            if(digit[i]==0) continue;
            digit[i]--;
            for(int j=0;j<=9;j++){
                if(digit[j]==0) continue;
                digit[j]--;
                for(int k=0;k<=8;k+=2){
                    if(digit[k]==0){
                        continue;
                    }
                    ans++;
                }
                digit[j]++;
            }
            digit[i]++;
        }
        return ans;
    }
};