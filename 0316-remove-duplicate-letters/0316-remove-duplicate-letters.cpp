class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        vector<int> vis(26,false);
        for(auto c:s){
            freq[c-'a']++;
        }
        string ans="";
        for(auto c:s){
            freq[c-'a']--;
            if(vis[c-'a']) continue;

            while(!ans.empty() && ans.back()>c && freq[ans.back()-'a']>0){
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }

            vis[c-'a']= true;
            ans.push_back(c);
        }
        return ans;
    }
};