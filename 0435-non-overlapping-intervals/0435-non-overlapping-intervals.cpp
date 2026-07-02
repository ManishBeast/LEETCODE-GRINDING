class Solution {
public: 
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        int farthest =INT_MIN;
        for(auto it:intervals){
            if(it[0]>=farthest){
                cnt++;
                farthest = it[1];
            }
        }
        return intervals.size()-cnt;
    }
};