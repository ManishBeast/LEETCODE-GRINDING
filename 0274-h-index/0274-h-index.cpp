class Solution {
public:
    int ans(int mid,vector<int>&nums){
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=mid){
                count++;
            }
        }
        return count;
    }
    int hIndex(vector<int>& citations) {
        int left =0;
        int right =*max_element(citations.begin(),citations.end()); 
        int temp=0;
        while(left<=right){
            int mid = left+(right-left)/2;
            int k = ans(mid,citations);
            if(k>=mid){
                temp = mid;
                left=mid+1;
            }else if(k<mid){
                right = mid-1;
            }
        }
        return temp;
    }
};