class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        queue<char> q;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                    while(!st.empty() && st.top()!=')'){
                        char k = st.top();
                        st.pop();
                        q.push(k);
                    }
                    st.pop();
                    while(!q.empty()){
                        char k = q.front();
                        q.pop();
                        st.push(k);
                    }
            }else{
                st.push(s[i]);
            }
        }
        string d = "";
        while(!st.empty()){
            char m = st.top();
            st.pop();
            d.push_back(m);
        } 
        return d;
    }
};