class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(auto it:nums) freq[it]++;
        priority_queue<pair<int,int>> pq;
        for(auto it:freq){
            pq.push({it.second,it.first});
        }
        vector<int> temp;
        for(int i=0;i<k;i++){

        temp.push_back(pq.top().second);
         pq.pop();
        }
        return temp;
    }
};