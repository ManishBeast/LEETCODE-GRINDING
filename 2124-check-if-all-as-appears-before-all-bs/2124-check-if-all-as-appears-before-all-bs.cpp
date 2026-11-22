class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int endA = -1; 
        int startB = n;  
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                endA = max(endA, i);
            } else {
                startB = min(startB, i);
            }
        }
        return endA < startB;
    }
};