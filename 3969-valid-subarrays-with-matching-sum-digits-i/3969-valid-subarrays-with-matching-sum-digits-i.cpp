class Solution {
public:
    int check(long long n){
        int count =0;
        while(n){
            n=n/10;
            count++;
        }
        return count;
    }
    bool isValid(long long sum,int number,int x){
        int k = sum%10;
        int k1= sum/pow(10,number);
        if(k==x && k1==x) return true;
        return false;
    }
    
    int countValidSubarrays(vector<int>& nums, int x) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            long long sum =0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                int number = check(sum);
                if(isValid(sum,number-1,x)){
                    count++;
                }
            }
        }
        return count;
    }
};