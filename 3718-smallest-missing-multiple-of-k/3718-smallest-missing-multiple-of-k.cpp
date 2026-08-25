class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;
        for(auto it:nums){
            if(it%k==0){
            st.insert(it);
            }
        }
        int ans =0;
        int i=1;
        int last=0;
        for(auto it:st){
            if(it!=i*k){
                ans=i*k;
                break;
            }
            i++;
            last = it;
        }
        
        if(ans==0) return i*k;
        return ans;
    }
};