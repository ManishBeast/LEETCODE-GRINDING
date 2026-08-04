class Solution {
public:
    vector<long long> temp(vector<int>& monsters,vector<vector<int>>&boosts){
        int n = monsters.size();
        vector<long long> diff(n+1,0);
        vector<long long> bonus(n,0);
        for(auto &it:boosts){
            int a =it[0];
            int b = it[1];
            int c =it[2];
            diff[a]+=c;
            if(b+1<n){
                diff[b+1] -=c;
            }
        }
        long long sum =0;
        for(int i =0;i<n;i++){
            sum+=diff[i];
            bonus[i] = sum;
        }
        return bonus;
    }
    bool can(long long mid,vector<int>& monsters, vector<long long> & bonus){
        for(int i=0;i<monsters.size();i++){
            if(mid+bonus[i]<monsters[i]){
                return false;
            }
            mid = max(0LL,mid - 1LL*monsters[i]);
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        long long low =0;
        long long high = 0;
        vector<long long> bonus = temp(monsters,boosts);
        for(auto it:monsters){
            high+=it;
        }
        while(low<high){
            long long mid = low+(high-low)/2;
            if(can(mid,monsters,bonus)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};