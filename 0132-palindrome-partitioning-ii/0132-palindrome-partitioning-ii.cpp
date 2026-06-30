class Solution {
public:
 bool isPalindrome(string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}
    int ans(string s,int i,vector<int> &dp){
        if(i==s.size()){
            return 0;
        }
        int minCost = INT_MAX;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<s.size();j++){
            if(isPalindrome(s,i,j)){
                int cnt = 1+ans(s,j+1,dp);
                minCost = min(minCost,cnt);
            }
        }
        return dp[i]=minCost;
    }
    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        int n = s.size();
        return ans(s,0,dp)-1;
    }
};