class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};
        while(!q.empty()){
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr= r+delRow[i];
                int nc = c+delCol[i];
                  if(nr>=0 && nr<n && nc>=0 && nc<n &&
                   dist[nr][nc]==INT_MAX) {
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> best(n, vector<int>(n,-1));

        pq.push({dist[0][0], {0,0}});
        best[0][0]=dist[0][0];

        while(!pq.empty()) {

            auto [safe,pos]=pq.top();
            pq.pop();

            auto [r,c]=pos;

            if(r==n-1 && c==n-1)
                return safe;

            for(int k=0;k<4;k++) {

                int nr=r+delRow[k];
                int nc=c+delCol[k];

                if(nr<0||nr>=n||nc<0||nc>=n)
                    continue;

                int newSafe=min(safe,dist[nr][nc]);

                if(newSafe>best[nr][nc]) {
                    best[nr][nc]=newSafe;
                    pq.push({newSafe,{nr,nc}});
                }
            }
        }

        return 0;


    }
};