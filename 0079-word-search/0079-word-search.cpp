class Solution {
public:
    bool dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &board,string& word,int idx){
        vis[row][col]=1;
        int n = board.size();
        if(idx==word.size()) return true; // as idx start from 1 for dfs starting so if idx lenght
        int m = board[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = row+delRow[i];
            int nc = col+delCol[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc]){
                if(word[idx]==board[nr][nc]){
                   
                    if(dfs(nr,nc,vis,board,word,idx+1)==true){
                        return true;
                    } 
                }
            }
        }
        vis[row][col]=0;
        return false; // as we traverse that path and yet didn't get the path which includes all the string element so we will return false for that path only bro ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int idx =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[idx]==board[i][j]){
                    if(dfs(i,j,vis,board,word,idx+1)==true) return true;
                }
            }
        }
        return false;
    }
};