class Solution {
public:

    void getallsubset(vector<int>& nums ,vector<int>& ans, int i, vector<vector<int>>& allsubset){
        if(i == nums.size()){
            allsubset.push_back({ans});
            return;
        }

        //include
        ans.push_back(nums[i]);
        getallsubset(nums, ans, i+1, allsubset);

        //Exclude
        ans.pop_back(); // before going back remove the last element from the answer(subset)

        // skip the same number untill we got a different number
        int idx = i+1;
        while(idx <  nums.size() && nums[idx] == nums[i]){
            idx++;
        }
        getallsubset(nums, ans, idx, allsubset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allsubset;
        vector<int> ans;

        getallsubset(nums, ans, 0, allsubset);

        return allsubset;
    }
};