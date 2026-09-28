class Solution {
public:
    int maxDepth(string s) {
        int maxi =0;
        int count =0;
        for(auto ch:s){
            if(ch=='('){
                count++;
                maxi = max(maxi,count);
            }else if(ch==')'){
                count--;
            }
        }
        return maxi;
    }
};