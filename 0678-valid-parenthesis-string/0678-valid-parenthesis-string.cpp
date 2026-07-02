class Solution {
public:
    int ans(string s,int ind,int cnt,vector<vector<int>> &dp){
        if(cnt<0) return false;
        if(ind==s.size()) return cnt==0;
        if(dp[ind][cnt]!=-1) return dp[ind][cnt];
        if(s[ind]==')') return dp[ind][cnt]=ans(s,ind+1,cnt-1,dp);
        if(s[ind]=='(') return dp[ind][cnt]=ans(s,ind+1,cnt+1,dp);
        return dp[ind][cnt]=ans(s,ind+1,cnt-1,dp)||ans(s,ind+1,cnt,dp)||ans(s,ind+1,cnt+1,dp);
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return ans(s,0,0,dp);
    }
};