class Solution {
public:
    int longestValidParentheses(auto& s) {
        int ans = 0;
        int n = s.size();
        vector<int> st = {-1};
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push_back(i);
            else {
                st.pop_back();
                
                if (st.empty())
                    st.push_back(i);
                else
                    ans = max(ans, i - st.back());
            }
        }
        
        return ans;
    }
};