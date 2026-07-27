class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        string ans = "";

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            int left = i;

            while (i >= 0 && s[i] != ' ')
                i--;

            ans += s.substr(i + 1, left - i);

            while (i >= 0 && s[i] == ' ')
                i--;

            if (i >= 0)
                ans += ' ';
        }

        return ans;
    }
};