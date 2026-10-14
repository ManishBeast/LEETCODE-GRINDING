class Solution {
public:

    int beautySum(string s) {
        int n = s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int> freq(26,0);
                for(int k=i;k<=j;k++){
                    freq[s[k]-'a']++;
                }
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(int p=0;p<26;p++){
                    if(freq[p]==0) continue;
                    maxi = max(maxi,freq[p]);
                    mini = min(mini,freq[p]);
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};