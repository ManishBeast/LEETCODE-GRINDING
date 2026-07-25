class Solution {
public:
    int maxProduct(int n) {
        int maxi =0;
        int secondMaxi =0;
        while(n>0){
            int k = n%10;
            if(maxi<=k){
                secondMaxi = maxi;
                maxi =k;
            }else if(k<maxi && secondMaxi<k){
                secondMaxi = k;
            }
            n = n/10;
        }
        return secondMaxi*maxi;
    }
};