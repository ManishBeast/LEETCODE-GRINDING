class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int heal) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};

        while(!pq.empty()){
            int healthE = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(healthE>dist[r][c]) continue; // bro as if health wha pe pahuchna mein woh pehle se hi km h so r and c ke liye dusra check kyu means dist mein pehle se hi shi value added h so chilll pilll

            for(int i=0;i<4;i++){
                int nRow = r+delRow[i];
                int nCol = c+delCol[i];
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<m ){
                    int newCost = healthE + grid[nRow][nCol];

                    if(newCost < dist[nRow][nCol]) {
                        dist[nRow][nCol] = newCost;
                        pq.push({newCost,{nRow,nCol}});
                    }
                }
            }
        }
        if(dist[n-1][m-1]>=heal) return false;
        return true;
    }
};