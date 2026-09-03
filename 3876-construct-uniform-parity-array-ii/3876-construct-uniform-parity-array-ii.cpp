class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddN=INT_MAX;
        int evenN=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0) evenN = min(evenN,nums1[i]);
            else oddN = min(oddN,nums1[i]);
        }
        if(oddN==INT_MAX) return true;
        return oddN<evenN;
    }
};