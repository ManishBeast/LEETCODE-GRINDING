class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int j=0;
        int i=0;
        if(k==0) return grid;
        vector<vector<int>> newGrid(n,vector<int>(m,0));
        while(k>0){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int newCol = (j+1)%m;
                    newGrid[i][newCol] = grid[i][j];
                }
            }
        newGrid[0][0]=grid[n-1][m-1];
        for(int k=1;k<n;k++){
            newGrid[k][0]=grid[k-1][m-1];
        }
        k--;
        grid = newGrid;
        }
        return newGrid;
    }
};