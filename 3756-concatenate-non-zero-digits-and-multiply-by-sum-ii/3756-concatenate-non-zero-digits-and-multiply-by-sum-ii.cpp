class Solution {
public:
    int mod = 1e9+7;
    // long long number(string &s,int l,int r){
    //     long long j =1;
    //     long long sum =0;
    //     long long m =0;
    //     for(int i =r;i>=l;i--){
    //         int k = s[i]-'0';
    //         if(k!=0){
    //         m=(m+j*k)%mod;
    //         j = (10*j)%mod;
    //         sum=(sum+ k)%mod;
    //         }
    //     }
    //     return (long long)(sum*m)%mod ;
    // }


    // int digit(int a){
    //     int cnt =0;
    //     while(a>0){
    //         a = a/10;
    //         cnt++;
    //     }
    //     return cnt;
    // }.          we can't do this because bro think yoursefl the prefix will store the int value and it will become so long and for that we r storing it by doing mod and that value changes so we have to use array to store those inspite of usong this method 



    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> temp;
        vector<int> sum(s.size());
        vector<int> prefix(s.size());
        vector<long long> p10(s.size() + 1, 1);
        vector<int> nonZeroCount(s.size());
        for(int i=1; i<=s.size(); i++) {
            p10[i] = (p10[i-1] * 10) % mod;
        }
        int k=0;
        for(int i=0;i<s.size();i++){
            k += s[i]-'0';
            sum[i] = k;
        }
        int j =1;
        long long ans = 0; 
        int nz = 0;
        for(int i=0;i<s.size();i++){
            int q = s[i]-'0';
            if(q != 0){
                ans = (ans * 10 + q) % mod;
                nz++;
            }
            prefix[i] = ans;
            nonZeroCount[i] = nz;
        }
        for(int i=0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int x =0;
            if(left>0){
               x = sum[right]-sum[left-1];
            }else{
                x = sum[right];
            }
            long long sumFinal = prefix[right];
            if(left > 0) {
                int count_in_left = nonZeroCount[right] - nonZeroCount[left-1];
                sumFinal = (prefix[right] - (1LL * prefix[left-1] * p10[count_in_left]) % mod + mod) % mod;
            }

            int answer = ((long long)x * sumFinal) % mod;                  
            temp.push_back(answer);
        }

        return temp;
    }
};

