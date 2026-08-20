class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        int n = nums.size();
        arr1.push_back(nums[0]);
        vector<int> ans;
        for(int i=1;i<n;i++){
            if(!arr2.empty() && arr1.back()>arr2.back()){
            arr1.push_back(nums[i]);
            }else{
            arr2.push_back(nums[i]);
            }
        }
        for(int i=0;i<arr1.size();i++){
            ans.push_back(arr1[i]);
        }
        for(int i=0;i<arr2.size();i++){
            ans.push_back(arr2[i]);
        }
        return ans;
    }
};