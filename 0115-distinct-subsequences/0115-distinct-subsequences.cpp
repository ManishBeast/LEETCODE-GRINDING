class Solution {
public:
vector<vector<int>> dp;
    int ans =0;
    int count(string s,string t,int idx1,int idx2){
        int n = s.size();
        if(idx2<0){
            return 1;
        }
        if(idx1<0){
            return 0;
        }
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1]==t[idx2]) {
            return dp[idx1][idx2] = count(s,t,idx1-1,idx2-1)+count(s,t,idx1-1,idx2);
        }
        return dp[idx1][idx2] = count(s,t,idx1-1,idx2); 
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.assign(n,vector<int>(m,-1));
        return count(s,t,n-1,m-1);
    }
};