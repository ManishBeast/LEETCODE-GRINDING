class Solution {
public:
    set<vector<int>> ans;
    void pnc(vector<int>&nums,int idx){
        if(idx==nums.size()){
            ans.insert(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            pnc(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        pnc(nums,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};