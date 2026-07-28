class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]] ++;
        }
        int n = s.size();
        int i=0;
        char left =0;
        string ans(s.size(),' ');
        for(auto it:mpp){
            char node = it.first;
            int count = it.second;
                while(count>=2){
                ans[i] = node;
                ans[s.size()-i-1] = node;
                i++;
                count=count-2;
                }
                if(count==1)
                    left = node;
            }
        if(left!=0){
        ans[s.size()/2] = left;
        }
        return ans;
    }
};