class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<int>> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i =0;i<n1;i++){
            pq.push({nums1[i]+nums2[0],0});
        }
        while(k-- && !pq.empty()){
            auto [sum,pos] = pq.top();
            pq.pop();
            ans.push_back({sum-nums2[pos],nums2[pos]});
            if(pos+1<n2){
            pq.push({sum-nums2[pos]+nums2[pos+1],pos+1});
            }
        }
        return ans;
    }
};