class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0;
        int temp=0;
        int total = 0;
        for (int start = 0; start < n; start++) {
            total+= gas[start]-cost[start];
            temp += gas[start]-cost[start];
            if(temp<0){
                ans = start+1;
                temp =0;
            }
        }
        if(total<0){
            return -1;
        }

        return ans;
    }
};