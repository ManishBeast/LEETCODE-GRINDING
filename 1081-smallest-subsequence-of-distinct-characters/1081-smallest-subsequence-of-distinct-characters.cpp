class Solution {
public:
  
    string smallestSubsequence(string s) {
       vector<int> vis(26,0);
       vector<int> freq(26,false);
       for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
       }
       string ans ="";
       for(auto it:s){
        freq[it-'a']--;
         if (vis[it - 'a']){
                continue;
         }
        while(!ans.empty() && ans.back()>it &&  freq[ans.back()-'a']>0){
            vis[ans.back()-'a']=false;
            ans.pop_back();
        }
        ans.push_back(it);
        vis[it-'a']=true;
       }
       return ans;
    }
};