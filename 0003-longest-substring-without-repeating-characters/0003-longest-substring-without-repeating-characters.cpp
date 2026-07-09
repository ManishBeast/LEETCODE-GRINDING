class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int right =0;
        int n = s.size();
       vector<int> hash(256,0);
        int maxi =0;

        while(right<n){
            while(hash[s[right]]>0){
                hash[s[left]]--;
                left++;
            }
            hash[s[right]]++;
            maxi = max(maxi , right-left+1);
            right++;
        }
        return maxi;
    }
};