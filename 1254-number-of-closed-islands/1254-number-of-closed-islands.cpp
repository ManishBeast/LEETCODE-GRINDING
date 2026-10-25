class Solution {
public:
    bool dfs(int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (x < 0 || y < 0 || x >= m || y >= n)
            return false;

        if (grid[x][y] == 1 || vis[x][y])
            return true;

        vis[x][y] = true;

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        bool closed = true;

        for (int i = 0; i < 4; i++) {
            int delRow = x + row[i];
            int delCol = y + col[i];

            if (!dfs(delRow, delCol, vis, grid)) {
                closed = false;
            }
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    if (dfs(i, j, vis, grid)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};