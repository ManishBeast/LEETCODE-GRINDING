class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n,INT_MAX);
        vis[0]=0;
        for(int i=0;i<nums.size();i++){
            if(vis[i] == INT_MAX) continue;   // unreachable
            int ch = nums[i];
            int left = i+1;
            while(ch>0 && left<n){
                vis[left] = min(vis[left],vis[i]+1);
                ch--;
                left++;
            }
        }
        return vis[n-1];
    }
};
