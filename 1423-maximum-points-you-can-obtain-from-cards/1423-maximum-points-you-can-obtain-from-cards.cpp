class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int leftSum =0;
        int n = nums.size();     
        int rightSum=0;
        int sum =0;
        for(int i=0;i<k;i++){
            leftSum+= nums[i];
        }
        sum = leftSum;
        int lastIndex = n-1;

        for(int i=k-1;i>=0;i--){
            leftSum -= nums[i];
            rightSum = rightSum+nums[lastIndex];
            lastIndex--;
            sum = max(sum,leftSum+rightSum);
        }

        
        return sum;
    }
};