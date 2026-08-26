class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        map<char, int> mpp;
        int left = 0;
        int right = 0;

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
        > pq;

        while (right < n) {
            mpp[s[right]]++;

            while (mpp['1'] > k) {
                mpp[s[left]]--;
                left++;
            }

            if (mpp['1'] == k) {
                int temp = left;

                while (temp <= right && s[temp] == '0') {
                    temp++;
                }

                string ans = "";

                for (int i = temp; i <= right; i++) {
                    ans += s[i];
                }

                pq.push({ans.size(), ans});
            }

            right++;
        }

        if (pq.empty())
            return "";

        return pq.top().second;
    }
};