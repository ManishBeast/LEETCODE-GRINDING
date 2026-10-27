class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m,string(n,'#'));
        if(m==1){
            for(int i=0;i<n;i++){
                ans[0][i]='.';
            }
        }
        if(n==1){
            for(int i=0;i<m;i++){
                ans[i][0]='.';
            }
        }
        for(int i=0;i<m;i++){
            ans[i][0]='.';
        }
        
        for(int i=0;i<n;i++){
            ans[m-1][i]='.';
        }
        return ans;
    }
};