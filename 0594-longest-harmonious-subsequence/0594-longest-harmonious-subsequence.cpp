class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            ++frequencyMap[num];
        }

        int ans = 0; // ans == longestHarmoniousSequence

        for (auto& [num, count] : frequencyMap) {
            if (frequencyMap.count(num + 1)) {
                ans = max(ans, count + frequencyMap[num + 1]);
            }
        }

       
        return ans;
    }
};