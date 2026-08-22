class Solution {
public:
    bool checkDivisibility(int n) {
        int m = n;
        int prd=1;
        int sum=0;
        while(m){
            int k = m%10;
            sum+=k;
            prd*=k;
            m=m/10;
        }
        if(sum+prd==0) return false;
        return (n%(sum+prd)==0);
    }
};