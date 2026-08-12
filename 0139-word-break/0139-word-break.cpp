class Solution {
public:
 vector<int> dp;
    bool ans(int idx,string s,set<string>&st){
        int n = s.size();
        string temp="";
        if(idx==n){
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<n;i++){
            temp+=s[i];
            if(st.find(temp)!=st.end()){
                if(ans(i+1,s,st)){
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         set<string> st;
         int n = wordDict.size();
         dp.assign(s.size()+1,-1);
         
         for(int i=0;i<n;i++){
            st.insert(wordDict[i]);
         }
       return ans(0,s,st);
    }
};