class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi =0;
        long long sum = 0;
        vector<int> prefixGcd;
        for(int i=0;i<nums.size();i++){
            maxi = max(nums[i],maxi);
            prefixGcd.push_back(gcd(maxi,nums[i]));
        }
        int left =0;
        int right = prefixGcd.size()-1;
        sort(prefixGcd.begin(),prefixGcd.end());
        while(left<right){
                sum =sum+ gcd(prefixGcd[left],prefixGcd[right]);
                left++;
                right--;
        }
        return sum ;
    }
};