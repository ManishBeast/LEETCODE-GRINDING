class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj,
             vector<int>& comp) {
        vis[node] = 1;
        comp.push_back(node);

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, vis, adj, comp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, vis, adj, comp);
                int sz = comp.size();
                bool ok = true;
                for (int node : comp) {
                    if (adj[node].size() != sz - 1) {
                        ok = false;
                        break;
                    }
                }

                if (ok) ans++;
            }
        }

        return ans;
    }
};