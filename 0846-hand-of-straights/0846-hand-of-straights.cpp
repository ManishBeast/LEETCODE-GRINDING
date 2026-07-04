class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> freq;
        int n = hand.size();
        for(int i=0;i<n;i++){
            freq[hand[i]]++;
        }

        for(auto it:freq){
            int node = it.first;
            int cnt = it.second;
            while(cnt>0){
                for(int i=0;i<groupSize;i++){
                    if(freq[node+i]==0){ // we are checking this bz hme consecutive cards chahiye as mentioned bro
                        return false;
                    }
                    freq[node+i]--;
                }
                cnt = freq[node];
            }
        }
        return true;
























        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // for(int i=0;i<hands.size();i++){
        //     freq[hands[i]]++;
        // }
        // for(auto it:freq){
        //     pq.push(it[1],it[0]);
        // }
      
        // while(!pq.empty()){
        //     vector<int>temp;
        //     for(int i=0;i<groupSize;i++){
        //         int cnt = pq.top().first;
        //         int node = pq.top().second;
        //         cnt--;
        //         temp.push_back(freq[node]);
        //         temp1.push_back(node);
        //     }
        //     for(auto i=0;i<temp.size();i++){
        //         if(temp[i]>0){
        //             pq.push({temp[i],temp1[i]});
        //         }
        //     }
        //     if(pq.empty()){
        //         return true;
        //     }
        // }
        // return false;
    }
};