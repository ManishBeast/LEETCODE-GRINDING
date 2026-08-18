class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> mpp;
        int n = nums.size();
        int maxi =-1;
        for(int i=0;i<nums.size();i++){
            vector<int> temp(51);
            for(int j=0;j<k && k+i<=n ;j++){
                temp[nums[i+j]]++;
                if(temp[nums[j+i]]==1){
                mpp[nums[j+i]]++;
                }
            }
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second==1){
                ans = it.first;
                maxi = max(maxi,ans);
            }
        }
        return maxi;
    }
};