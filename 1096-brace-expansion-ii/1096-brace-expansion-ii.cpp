#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    set<string> multiply(set<string> a, set<string> b) {
        set<string> ans;

        for (string x : a) {
            for (string y : b) {
                ans.insert(x + y);
            }
        }

        return ans;
    }

    set<string> solve(string& s, int& i) {
        set<string> ans;
        set<string> curr = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++;

                set<string> temp = solve(s, i);
                curr = multiply(curr, temp);

                i++;
            }

            else if (s[i] == ',') {
                ans.insert(curr.begin(), curr.end());

                curr.clear();
                curr.insert("");

                i++;
            }

            else {
                set<string> temp = {string(1, s[i])};
                curr = multiply(curr, temp);

                i++;
            }
        }

        ans.insert(curr.begin(), curr.end());

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};