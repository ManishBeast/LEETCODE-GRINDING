class Solution {
public:

	bool check(int mid, int n, long long k, vector<vector<pair<int,int>>> &adj) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > k) 
                return false;

            if(node == n - 1) 
                return true;

            if(d > dist[node]) 
                continue;

            for(auto &vec : adj[node]) {
                int adjNode  = vec.first;
                int edgeCost = vec.second;

                if(edgeCost < mid)  //because I want the score to be mid
                    continue;

                if(d + edgeCost < dist[adjNode]) {
                    dist[adjNode] = d + edgeCost;
                    pq.push({d + edgeCost, adjNode});
                }
            }
        }

        return false;
	}

	int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
		int n = online.size();
        vector<vector<pair<int,int>>> adj(n);

		int l = INT_MAX;
        int r = 0;

		for(auto &edge : edges) {
		    int u = edge[0];
		    int v = edge[1];
		    int w = edge[2];

		    if(!online[u] || !online[v]) 
                continue;
                
		    adj[u].push_back({v, w});
		    l = min(l, w);
		    r = max(r, w);
		}

        int answer = -1;

		while(l <= r) {
		    int mid = l + (r - l) / 2;

		    if(check(mid, n, k, adj)) {
                answer = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
		}

		return answer;
	}
};