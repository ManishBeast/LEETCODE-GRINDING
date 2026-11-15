class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count =0;
        int prefixSum;
        int oddC=0;
        int evenC=1;
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            if(prefixSum%2==0){
                count+=oddC;
                evenC++;
            }else{
                count+=evenC; // as if no even subarraay sum is there all the subarray sum will be odd
                oddC++;
            }
            count%=mod;
        }
        return count ;
    }
};