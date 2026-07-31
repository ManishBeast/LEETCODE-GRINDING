class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue<
            pair<long long, pair<int,int>>,
            vector<pair<long long, pair<int,int>>>,
            greater<pair<long long, pair<int,int>>>
        > pq;
        vector<vector<pair<int,int>>> adj(n);
        // distance ,node,consecutiveCount
        pq.push({0,{0,1}});
        vector<vector<long long>> dist(n,vector<long long>(k+1,LLONG_MAX));
        dist[0][1] = 0; // node,count


        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            long long dis = top.first;
            int node = top.second.first;
            int cnt = top.second.second;

            if(dis != dist[node][cnt])
                continue; // this terminates all the distance which is greater than the dis we already counted

            if(node==n-1){
                    return dis;
            } // yhi last point h 
          
            for(auto &it:adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                  int newCnt=1;
                if(labels[node] == labels[adjNode]){
                    newCnt = cnt + 1;
                }else{
                    newCnt = 1;
                }
                if(newCnt > k)
                    continue; // skip kr rha h saara jiska consecutive req se jyada h 
                long long newDis = dis + adjWt;
                if(newDis < dist[adjNode][newCnt]){
                    dist[adjNode][newCnt] = newDis;
                    pq.push({newDis,{adjNode, newCnt}});
                }
            }
        }
    return -1;
    }
};