class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        int zc = 0;
        for(int i=0; i<n; i++){
            if(nums[i]!=0) a.push_back(nums[i]);
            else zc++;
        }
        for(int i=0; i<zc; i++){
            a.push_back(0);
        }
        
        nums = a;
    }
};