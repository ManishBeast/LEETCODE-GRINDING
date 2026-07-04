class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>> &adj,vector<int> &vis,int &mini){
        vis[node] = 1;
        for(auto &it:adj[node]){
            int adjNode = it.first;
            int weight = it.second;
            mini = min(mini,weight);
            if(!vis[adjNode]){
                dfs(adjNode,adj,vis,mini);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        int mini= INT_MAX;
        for(auto &it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>vis(n+1,0);
        dfs(1,adj,vis,mini);
        
        return mini;
    }
};