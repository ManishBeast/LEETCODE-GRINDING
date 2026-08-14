class Solution {
public:
    int reverseBits(int n) {
        string ans ="";
        long long sum =0;
        for(int i=0;i<32;i++){
            ans += char('0'+(n&1));
            n = n>>1;
        }
        for(int i=0;i<ans.size();i++){
            sum+= (ans[i]-'0')*pow(2,ans.size()-i-1); 
        }
        return sum;
    }
};