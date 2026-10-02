class Solution {
public:
    vector<string> results;
    void ans(vector<char> &temp,vector<char> &temp1,int idx,int idx1,int count,string s){
        int n = temp.size();
        int m = temp1.size();
        if(idx==n && idx1==m){
            if(count==0) {
                results.push_back(s);
                return;
            }
            return ;
        }
        if(idx<n){
        ans(temp,temp1,idx+1,idx1,count+1,s+temp[idx]);
        }
        if(idx1<m && count>0){
        ans(temp,temp1,idx,idx1+1,count-1,s+temp1[idx1]);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<char> temp;
        vector<char> temp1;
        for(int i=0;i<n;i++){
            temp.push_back('(');
            temp1.push_back(')');
        }
        ans(temp,temp1,0,0,0,"");
        return results;
    }
};