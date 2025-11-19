class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums[i] == o){
                o = 2 * o;
            }
        }

        return o;
    }
};