class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi =0;
        int left =0;
        int right =0;
        vector<int> hash(256,-1);
        while(right<n){
            int ind = s[right];
            if(hash[ind]!=-1){
                left = max(left,hash[ind]+1);
            }
            hash[ind]=right;
            maxi = max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};