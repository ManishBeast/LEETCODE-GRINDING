class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int left =0;
        int right =0;
        int maxi = 0;
        int count =0;
        map<char,int> mpp;
        while(right<n){
            mpp[s[right]]++;
            while(mpp[s[right]]>2){
                mpp[s[left]]--;
                left++;
            }
            maxi = max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};