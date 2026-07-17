class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        //           INCLUSION AND EXCLUSION METHOD 
       int m = *max_element(nums.begin(),nums.end());
       vector<long long> cnt(m+1);
       for(int num:nums){
        cnt[num]++;
       }
       for(int i=1;i<=m;i++){
        for(int j=i*2 ;j<=m;j+=i){
            cnt[i]+=cnt[j];
        }
       }
        for (int i = 1; i <= m; i++) {
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        }
        for (int i = m; i >= 1; i--) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] -= cnt[j]; // as cnt mein jo counted h saare jo ek no. se dvide ho rhe h but not contains exact no. gcd equal to g so substract divisible by 2 - gcd(4)-gcd(8) understood
            }
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
         vector<int> ans;
        for (long long q : queries) {
            q++; // as queires is 0 index and cnt is 1 index
            int pos = lower_bound(cnt.begin(), cnt.end(), q) - cnt.begin();
            ans.push_back(pos);
        }
        return ans;
    }
};