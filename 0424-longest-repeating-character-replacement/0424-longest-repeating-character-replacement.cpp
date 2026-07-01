class Solution {
public:
    int characterReplacement(string s, int k) {
           int n = s.size();
        int maxLen =0;
        int left =0;
        int right =0;
        int hash[26] = {0};
        int maxFreq = 0;
        while(right<n){
                hash[s[right]-'A']++;
                maxFreq = max(maxFreq,hash[s[right]-'A']);
                int change = (right-left+1) - maxFreq;
                if((right-left+1) - maxFreq>k){
                    hash[s[left]-'A']--;
                    left++;
                }
                if((right-left+1) - maxFreq<=k){
                maxLen = max(maxLen,right-left+1);
                }
                right++;
        }
        return maxLen;
    }
};