class Solution {
public:
    bool check(int row,int col,vector<string> &board){
        int n = board.size();
        int m = board[0].size();
        int rowE = row;
        int colE = col;
        while(colE>=0){
            if(board[row][colE]=='Q') return false;
            colE--;
        }
        colE=col;
        while(rowE>=0 && colE>=0 ){
            if(board[rowE][colE]=='Q') return false;
            rowE--;
            colE--;
        }
        rowE = row;
        colE = col;
        while(rowE<n && colE>=0){
            if(board[rowE][colE]=='Q') return false;
            rowE++;
            colE--;
        }
        return true;
    }

    void ans(vector<string>&board,vector<vector<string>>&temp,int col){
        int n = board.size();
        if(col==n){
            temp.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(check(i,col,board)){
                board[i][col]='Q';
                ans(board,temp,col+1);
            }
            board[i][col]='.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> temp;
        vector<string> board(n);
        string s(n,'.');
        for(int i =0;i<n;i++){
            board[i]=s;
        }
        ans(board,temp,0);
        return temp;
    }
};