class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<ratings.size();i++){
            pq.push({ratings[i],i});
        }
        vector<int> ans(n,1);
        while(!pq.empty()){
            auto[node,idx] = pq.top();
            pq.pop();
            if(idx>0 && ratings[idx]>ratings[idx-1]){
                ans[idx] = max(ans[idx],ans[idx-1]+1);
            } 

            if(idx<n-1 && ratings[idx]>ratings[idx+1]){
                ans[idx] = max(ans[idx],ans[idx+1]+1);
            } 
    }
    int x =0;
    for(auto &it:ans){
        x+=it;
    }
    return x;
    }
};