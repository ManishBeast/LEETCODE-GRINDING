class Solution {
public:
    string maximum(vector<int>&cnt){
        string ans="";
        for(int i=25;i>=0;i--){
            ans.append(cnt[i],'a'+i);
        }
        return ans;
    }
    string minimum (vector<int>&cnt){
        string ans="";
        for(int i=0;i<26;i++){
            ans.append(cnt[i],'a'+i);
        }
        return ans;
    }
    bool canMakeGreater(vector<int>&cnt,string target,int idx){
        string ans = target.substr(idx);
        string maxstr = maximum(cnt);
        return maxstr>ans;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        string ans ="";
        vector<int> cnt(26);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            int targetCh = target[i]-'a';
            if(cnt[targetCh]>0){
                cnt[targetCh]--;
                if(canMakeGreater(cnt,target,i+1)){
                    ans.push_back(target[i]);
                    continue;
                }
                cnt[targetCh]++;
            }
            for(int x=targetCh+1; x<26;x++){
                if(cnt[x]>0){
                    ans.push_back(x+'a');
                    cnt[x]--;
                    ans+=minimum(cnt);
                    return ans;
                }
            }
            return "";
        }
        return "";
    }
};


