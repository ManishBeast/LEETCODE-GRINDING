class DisjointSet{
    public:
        vector<int> size,parent;
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<n+1;i++){
                parent[i]=i;
            }
        }
        int parentU(int a){
            if(a==parent[a]) return a;
            return parent[a] = parentU(parent[a]);
        }
        void unionBySize(int a,int b){
            int ulp_u = parentU(a);
            int ulp_v = parentU(b);
            if(ulp_u==ulp_v) return ;
           if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        sort(nums.begin(),nums.end());
        int left =0;
        int right =1;
         for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff)
                ds.unionBySize(i, i + 1);
        }
        vector<bool> temp;
        for(int i=0;i<queries.size();i++){
            int ulp_u = ds.parentU(queries[i][0]);
            int ulp_v = ds.parentU(queries[i][1]);
            temp.push_back(ulp_u==ulp_v);
        }
        return temp;
    }
};