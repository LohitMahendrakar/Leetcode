class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int s = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0)
                continue;

            if (nums[i] == s) {
                s++;
            }
            else if (nums[i] > s) {
                return s;
            }
            // if nums[i] < s, it's a duplicate, so ignore it
        }

        return s;
    }
};