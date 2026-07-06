class Solution {
public: 
    vector<vector<pair<int,int>>>dp;
    int mod =1e9+7;
    int getInt(char ch){
        return ch=='S'||ch=='E'?0:ch-'0';
    }
    bool isValid(int i,int j,vector<string>&board){
        return j>=0 && i>=0 && i<board.size() && j<board[0].size() && board[i][j]!='X';
    }
    pair<int,int> solve(int i,int j,vector<string> &board,vector<vector<pair<int,int>>> &dp){
        if(!isValid(i,j,board)){
            return {0,0};
        }
        if(board[i][j]=='E'){
            return {0,1};
        }
        if(dp[i][j]!=make_pair(-1,-1)) return dp[i][j];
        int bestScore =-1;
        long long bestPath = -1;
        vector<pair<int,int>> prev = {solve(i-1,j,board,dp),solve(i-1,j-1,board,dp),solve(i,j-1,board,dp)};
        for(auto[score,path]:prev){
            if(path==0) continue;
                score += getInt(board[i][j]);
            if(score>bestScore){
                bestScore = score;
                bestPath = path;
            }else if(score==bestScore){
                bestPath = bestPath + path;
            }
        }
        if(bestScore==-1) return dp[i][j] = {0,0};
        return dp[i][j] = {bestScore,(int)(bestPath%mod)};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
       dp.assign(n,vector<pair<int,int>>(m,{-1,-1}));
        auto node = solve(n-1,m-1,board,dp); 
        return {node.first,node.second};
    }
};