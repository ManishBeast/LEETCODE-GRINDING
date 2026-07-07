class Solution {
public:
    int n = 9;
    int m = 9;
    vector<int> check(int row,int col,vector<vector<char>> &board){
        int rowE =0 ;
        vector<int> mark(10,0);
        mark[0]=1; 
        if(row<3) rowE = 0;
        else if(row>=3 && row<6) rowE = 3;
        else rowE = 6;

         int colE =0 ;
        if(col<3) colE = 0;
        else if(col>=3 && col<6) colE = 3;
        else colE = 6;

        for(int i=rowE;i<rowE+3;i++){
            for(int j=colE;j<colE+3;j++){
                if(board[i][j]!='.')
                    mark[board[i][j]-'0']=1;
            }
        }
        for(int i=0;i<n;i++){

             if(board[i][col]!='.')
                    mark[board[i][col]-'0']=1;
            }
        for(int i=0;i<m;i++){
            if(board[row][i]!='.')
                    mark[board[row][i]-'0']=1;
            }
        return mark;
    }

    bool ans(vector<vector<char>> &board){
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    vector<int> temp = check(i,j,board);
                    for(int k=1;k<=n;k++){
                     if(temp[k]==0){
                        board[i][j]=k+'0';
                        if(ans(board)) return true;
                        board[i][j] = '.';
                     }
                }
            
                    return false;
                 }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        ans(board);
    }
};