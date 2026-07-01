class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int maxLen =0;
        // int sum =0;
        // int n = nums.size();
        // int left =0;
        // int right =0;
        // int cnt =0;
        // while(right<n && left){

        //     sum+= nums[right];
        //     while(sum>goal){
        //         sum-=nums[left];
        //         left++;
        //     }
        //     while(sum==goal){
        //          sum-=nums[left++];
        //          cnt++;
        //      }
        //     right++;
        // }
        // return cnt;

         map<int,int> mpp;
        int n = nums.size();
        int sum = 0;
        int count =0;
        // mpp[0]=1;

        for(int i =0;i<n;i++){
            sum+= nums[i];
            if(sum==goal){
                count ++;
            }

            int rem = sum - goal;
            if(mpp.find(rem)!=mpp.end()){
                count = count + mpp[rem];
            }
                mpp[sum]++;
        }
        return count;
    }
};