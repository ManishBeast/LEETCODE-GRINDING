class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<double> temp(n1+n2);
        int i=0;
        for(auto it:nums1){
            temp[i++]=it;
        }
        for(auto it:nums2){
            temp[i++] = it;
        }
        sort(temp.begin(),temp.end());
        double ans =0;
        if((n1+n2)&1) ans = temp[(n1+n2)/2];
        else ans = (temp[(n1+n2)/2-1]+temp[(n1+n2)/2])/2;
        return ans;
    }
};