class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int i =0;
        while(i<n){
            vector<int> curr = intervals[i];
            while(i+1<n && curr[1]>=intervals[i+1][0]){
                curr[0] = min(curr[0],intervals[i+1][0]);
                curr[1] = max(curr[1],intervals[i+1][1]);
                i++;
            }
            ans.push_back(curr);
            i++;
        }
        return ans;
    }
};