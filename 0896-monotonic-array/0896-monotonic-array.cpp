class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        std::vector<int> sortedAscending = nums;
        std::sort(sortedAscending.begin(), sortedAscending.end());

        std::vector<int> sortedDescending = nums;
        std::sort(sortedDescending.begin(), sortedDescending.end(), std::greater<int>());

        if (nums == sortedAscending || nums == sortedDescending) {
            return true;
        }
        
        return false;
    }
};