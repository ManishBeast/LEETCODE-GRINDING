class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum =0;
        int j =1;
        int x =0;
        while(n>0){
            int k = n%10;
            if(k!=0){
                x += j*k;
                j = 10*j;
                sum+= k;
            }
            n = n/10;
        }
        return (long long)sum*x;
    }
};