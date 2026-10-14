class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int n = nums.size()/2;
        int m = nums.size()-n;
        long long score=0;
        for(int i=0;i<nums.size();i++){
            if(i<n){
                score-=1LL*nums[i]*nums[i];
            }else{
                score+=1LL*nums[i]*nums[i];
            }
        }
        return score;
    }
};