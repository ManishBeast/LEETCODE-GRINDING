class Solution {
public:
    long long countWays(vector<int>& half, long long k) {
        long long ways = 1;
        int len = 0;

        for (int cnt : half) {
            if (cnt == 0) continue;

            len += cnt;

            int n = len;
            int r = min(cnt, n - cnt);

            long long nCr = 1;

            for (int i = 1; i <= r; i++) {
                nCr = nCr * (n - i + 1) / i;
                if (nCr > k) {
                    nCr = k + 1;
                    break;
                }
            }

            ways *= nCr;

            if (ways > k)
                return k + 1;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        vector<int> half(26, 0);

        string mid = "";

        int halfLen = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                mid += char(i + 'a');

            half[i] = freq[i] / 2;
            halfLen += half[i];
        }

        if (countWays(half, k) < k)
            return "";

        string firstHalf = "";

        for (int pos = 0; pos < halfLen; pos++) {

            for (int ch = 0; ch < 26; ch++) {

                if (half[ch] == 0)
                    continue;

                half[ch]--;

                long long ways = countWays(half, k);

                if (ways >= k) {
                    firstHalf += char(ch + 'a');
                    break;
                }

                k -= ways;
                half[ch]++;
            }
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        return firstHalf + mid + secondHalf;
    }
};