class Solution {
public:
    bool check(vector<int>&nums,int mid ,int m){
        int n = nums.size();
        int right = 0;
        int left =0;
        int cnt =1;
        while(right<n){
            int diff = nums[right]-nums[left];
            if(diff>=mid){
                cnt++;
                left = right;
            }
            right++;
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        if(m>n) return 0;
        sort(position.begin(),position.end());
        int left = 0;
        int right = position.back()-position.front();
        int ans =0;
        while(left<=right){
            int mid = left +(right-left)/2;
            if(check(position,mid,m)){
                ans = mid;
                left= mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};