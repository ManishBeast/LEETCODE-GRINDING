class Solution {
public:
    int n,m;
    int count=0;
    void dfs(int x,int y,vector<vector<int>> &vis,vector<vector<int>> &grid,long long& sum){
        if (x < 0 || y < 0 || x >= m || y >= n)
            return;
        if (grid[x][y] == 0 || vis[x][y])
            return;
        vis[x][y]=1;
        sum += grid[x][y];
        int row[] = {-1,0,1,0};
        int col[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int rowN = row[i]+x;
            int colN = col[i]+y;
            if(rowN>=0 && colN>=0 && rowN<m && colN<n){
                if (grid[rowN][colN] != 0 && !vis[rowN][colN]) {
                    dfs(rowN, colN, vis, grid, sum);
                }
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j] != 0 && !vis[i][j]) {
                    long long sum = 0;
                    dfs(i, j, vis, grid, sum);
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};