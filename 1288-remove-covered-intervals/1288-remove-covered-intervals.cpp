class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int maxRight = intervals[0][1];
        int cnt =0;
        for(int i=1;i<intervals.size();i++){
            if(maxRight>=intervals[i][1]){
                cnt++;
            }else{
                maxRight = intervals[i][1];
            }
        }
        return intervals.size()-cnt;
    }
};