class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans="";
        string res="";
        for(int i=0;i<s.size();i++){
            char ch =' ';
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                st.pop();
            }
            ans+=s[i];
            if(st.empty()){
                res+=ans.substr(1,ans.size()-2);
                ans="";
            }
        }
        return res;
    }
};