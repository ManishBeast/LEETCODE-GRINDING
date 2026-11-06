class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int len = logs.size();
        sort(logs.begin(),logs.end(),cmp);
        vector<pair<int, int>> qu;
        int q = queries.size();
        

        for(int i = 0; i < q; i++) {
            qu.push_back({queries[i], i});
        }
        sort(qu.begin(), qu.end());

        unordered_map<int, int> mp;
        vector<int> ans(q, 0);
        int l=0;
        int r=0;

        for(int i=0;i<qu.size();i++){
            int left = qu[i].first-x;
            int right = qu[i].first;
             while(r < len && logs[r][1] <= right) {
                mp[logs[r][0]]++;
                r++;
            }
            while(l < r && logs[l][1] < left) {
                mp[logs[l][0]]--;

                if(mp[logs[l][0]] == 0) {
                    mp.erase(logs[l][0]);
                }

                l++;
            }
            ans[qu[i].second] = n - mp.size();
        }
        return ans;
    }
};