class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int maxi =0;
        int sum =0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                maxi++;
            }else{
                maxi--;
                if(s[i-1]=='('){
                    sum+=1<<maxi;
                }
            }
        }
        return sum;
    }
};