class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0;
        int high = n1;
        int left = (n1+n2+1)/2;
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        double ans =0;
        while(low<=high){
            int mid = low + (high-low)/2;
            int j = left-mid;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            int l2 = INT_MIN;
            int l1 = INT_MIN;
            if(mid<n1) r1 = nums1[mid];
            if(j<n2) r2 = nums2[j];
            if(mid-1>=0) l1 = nums1[mid-1];
            if(j-1>=0) l2 = nums2[j-1];
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==1){
                    return max(l1,l2);
                }
                else {
                    return (double)(max(l1,l2)+min(r1,r2))/2;
                }
            }
            if(l1>r2){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return 0;
    }
};