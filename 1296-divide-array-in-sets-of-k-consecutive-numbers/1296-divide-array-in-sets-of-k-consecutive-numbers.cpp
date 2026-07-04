class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
       
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
    }
};