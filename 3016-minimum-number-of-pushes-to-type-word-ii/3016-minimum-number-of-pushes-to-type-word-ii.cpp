class Solution {
public:
    int minimumPushes(string word) {
        priority_queue<pair<int,char>> pq;
        map<char,int> mpp;
        for(int i=0;i<word.size();i++){
            mpp[word[i]]++;
        }
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        int ans=0;
        int i=1;
        int temp=2;
        while(!pq.empty()){
            auto [count,ch] = pq.top();
            pq.pop();
            if(temp>9){
                i++;
                temp=2;
            }
            ans+= i*count;
            temp++;
        }
        return ans;
    }
};