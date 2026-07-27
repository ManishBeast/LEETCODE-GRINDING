class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1)
            return s;

        int n = s.size();

        vector<vector<char>> ans(numRows, vector<char>(n, ' '));

        int row = 0;
        int col = 0;
        int j = 0;

        while (j < n) {

            for (row = 0; row < numRows && j < n; row++)
                ans[row][col] = s[j++];

            row = numRows - 2;
            col++;

            while (row > 0 && j < n) {
                ans[row][col] = s[j++];
                row--;
                col++;
            }
        }

        string temp = "";

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][j] != ' ')
                    temp += ans[i][j];
            }
        }

        return temp;
    }
};