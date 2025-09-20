class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;   // frequency map
        for (auto it : arr1) {
            mp[it]++;
        } 

        vector<int> ans;

        // Place elements in arr2 order
        for (int i = 0; i < arr2.size(); i++) {
            while (mp[arr2[i]] > 0) {
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }

        // Collect leftover elements
        vector<int> leftovers;
        for (auto &p : mp) {
            while (p.second > 0) {
                leftovers.push_back(p.first);
                p.second--;
            }
        }

        // Sort leftovers in ascending order
        sort(leftovers.begin(), leftovers.end());

        // Append to answer
        for (auto val : leftovers) {
            ans.push_back(val);
        }

        return ans;
    }
};
