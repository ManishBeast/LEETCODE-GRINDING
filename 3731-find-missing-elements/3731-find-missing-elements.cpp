class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int start = *min_element(nums.begin(),nums.end());
        int end = *max_element(nums.begin(),nums.end());
        vector<int> ans;
        for(int i = start;i<=end;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};