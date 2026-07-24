class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>st1;
        unordered_set<int>st2;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                st1.insert(nums[i]^nums[j]);
            }
        }
        for(auto it:st1){
            for(int j=0;j<nums.size();j++){
                st2.insert(it^nums[j]);
            }
        }
        return st2.size();
    }
};