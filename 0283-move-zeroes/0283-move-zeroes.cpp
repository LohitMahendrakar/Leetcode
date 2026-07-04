class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Swap non-zero element into the correct position
                swap(nums[insertPos], nums[i]);
                insertPos++;
            }
        }
    }
};