class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefMax = nums;
        vector<int> suffMin = nums;
        for(int i=1;i<n;i++){
            prefMax[i] = max(nums[i],prefMax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffMin[i]=min(nums[i],suffMin[i+1]);
        }
        for(int i=0;i<n;i++){
            int a = prefMax[i];
            int b = suffMin[i];
            if(a-b<=k){
                return i;
            }
        }
        return -1;
    }
};