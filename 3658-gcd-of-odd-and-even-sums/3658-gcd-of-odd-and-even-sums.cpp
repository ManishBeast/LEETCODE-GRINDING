class Solution {
public:
    int gcd(int a,int b){
        while(b){
           int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0;
        int evenSum =0;
        for(int i=1;i<=2*n;i++){
            oddSum+= i%2==1?i:0;
            evenSum+= i%2==0?i:0;
        }
        return gcd(oddSum,evenSum);
    }
};