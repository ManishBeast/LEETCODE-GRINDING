class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;
    bool dfs(int row,int col,vector<vector<int>>&temp,int sum){
        sum+=temp[row][col];
        if(sum<0) return false;
        if(row==n-1 && col==m-1){
             return sum==0;
        }
        bool down = false;
        bool right = false;
        if(dp[row][col][sum]!=-1) return dp[row][col][sum];
        if(row+1<n){
        down = dfs(row+1,col,temp,sum);
        }
        if(col+1<m){
        right = dfs(row,col+1,temp,sum);
        }
        return dp[row][col][sum]=down||right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();
         dp.assign(n,vector<vector<int>>(m+1,vector<int>(m+n+1,-1)));
        vector<vector<int>> temp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='('){
                    temp[i][j] = 1;
                }else{
                    temp[i][j] = -1;
                }
            }
        }
        if((m+n-1)%2==1) return false;

        return dfs(0,0,temp,0);
    }
};