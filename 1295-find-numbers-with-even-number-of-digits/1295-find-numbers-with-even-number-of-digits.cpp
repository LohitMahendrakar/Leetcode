class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int digit = 0;
            int num = nums[i];
            while(num > 0) {
                num = num / 10; // remove last digit
                digit++;
            }

            if(digit % 2 == 0) ans++;
        }
        return ans;
    }
};