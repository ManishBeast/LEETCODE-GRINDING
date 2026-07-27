class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int i=0;
        int n = strs.size();
        for(int i=1;i<strs.size();i++){
            string s2 =strs[i];
            int n1 = ans.size();
            int n2 = s2.size();
            int size = min(n1,n2);
            string temp="";
            for(int m=0;m<size;m++){
                if(ans[m]==s2[m]){
                    temp+=ans[m];
                }else{
                    break;
                }
            }
            ans = temp;
        }
         if (ans.empty())
                return "";
        return ans;
    }
};