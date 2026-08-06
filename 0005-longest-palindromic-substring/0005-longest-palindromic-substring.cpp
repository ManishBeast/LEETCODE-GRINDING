class Solution {
public:
    void ans(string &s,int l,int r,int &start, int &maxLen){
        int n = s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>maxLen){
                maxLen = r-l+1;
                start = l;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start=0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
             ans(s,i,i,start,maxi);
             ans(s,i,i+1,start,maxi);
        }
        return s.substr(start,maxi);
    }
};