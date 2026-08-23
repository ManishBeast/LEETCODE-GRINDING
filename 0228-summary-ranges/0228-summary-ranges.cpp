class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> temp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int start = i;
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            if (start == i) {
                temp.push_back(to_string(nums[start]));
            } else {
                temp.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            }
        }

        return temp;
    }
};