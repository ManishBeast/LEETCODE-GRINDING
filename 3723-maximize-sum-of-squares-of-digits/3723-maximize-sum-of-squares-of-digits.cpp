class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s="";
        while(num--){
            if(sum>=9){
                s+='9';
                sum-=9;
            }else{
                s+=sum+'0';
                sum-=sum;
            }
        }
        if(sum!=0) return "";
        return s;
    }
};