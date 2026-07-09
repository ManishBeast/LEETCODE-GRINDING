class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n = s.size();
        int i=n-1;
        int right =i;
        while(i>=0){
            while(i>=0 && s[i]==' '){
                i--;
            }
            if(i<0) break;
            right =i;
                
            while(i>=0 && s[i]!=' '){
                i--;
            }
            for(int j=i+1;j<=right;j++){
                ans+=s[j];
            }
             while(i>=0 && s[i]==' ')
                 i--;
            if(i>=0){
                ans+=' ';
            }
        }
        return ans;
    }
};