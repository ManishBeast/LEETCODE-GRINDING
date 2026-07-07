class Solution {
public:
    long long ans(vector<int>&piles,int mid){
        long long sum =0;
        for(int i=0;i<piles.size();i++){
            sum+= (piles[i]+mid-1)/mid;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left =1;
        int right = *max_element(piles.begin(),piles.end());
        while(left<=right){
            int mid = (right-left)/2+left;
            long long l = ans(piles,mid);
         if(l<=h){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }  
        return left;  
    }
};