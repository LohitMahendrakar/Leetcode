class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> chosen;
        vector<vector<int>> ans;
        function<void(int)> backtrack = [&](int start) {
            if (chosen.size() == k) {
                ans.push_back(chosen);
                return;
            }
            for (int i = start; i <= n; i++) {
                chosen.push_back(i);
                backtrack(i + 1);
                chosen.pop_back();
            }
        };
        backtrack(1);
        return ans;
    }
};