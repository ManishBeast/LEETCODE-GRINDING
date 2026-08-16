class Solution {
public:
    
    bool stoneGameIX(vector<int>& stones) {
        int sum =0;
        int n = stones.size();
        int count[3]={0};
        for(int x:stones){
            count[x%3]++;
        }
        if(count[1]==0 && count[2]==0) return false;
         if (count[0]%2 == 0) {
            return count[1]>0 && count[2]>0;
        }
         return abs(count[1] - count[2]) > 2;
    }
};