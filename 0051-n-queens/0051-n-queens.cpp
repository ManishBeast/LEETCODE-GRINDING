class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n) {
            // as we are putting from the left so we need to check in the left only that whether it is attacking it or not right that's it 
    int duprow = row;
    int dupcol = col;

    // Check upper-left diagonal
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = duprow;
    col = dupcol;

    // Check left side
    while (col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;

    // Check lower-left diagonal
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}
    void nQueen(int col,vector<vector<string>> &ans,vector<string> &board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<board.size();row++){
            if(isSafe(row,col,board,n)){
                board[row][col] ='Q';
                nQueen(col+1,ans,board,n);
                board[row][col] ='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        nQueen(0,ans,board,n);
        return ans;

    }
};