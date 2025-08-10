class Solution {
public:
    int trap(vector<int>& a) { // a == height array
        int n = a.size();
        if (n == 0) return 0;

        int ans = 0;      // Total amount of trapped water

        int lhd = a[0];   // lhd = Left Highest so far (maximum height seen from the left side)
        int rhd = a[n-1]; // rhd = Right Highest so far (maximum height seen from the right side)

        int i = 0;        // Left pointer (starts from the leftmost bar)
        int j = n - 1;    // Right pointer (starts from the rightmost bar)

        // Process until the two pointers meet
        while (i <= j) {

            // Compare the left and right highest walls
            if (lhd <= rhd) {
                // Move from the left side
                if (a[i] >= lhd) 
                    lhd = a[i]; // Update left highest if current bar is taller
                else 
                    ans += lhd - a[i]; // Water trapped is difference between left highest and current height
                i++; // Move left pointer forward
            }
            else {
                // Move from the right side
                if (a[j] >= rhd) 
                    rhd = a[j]; // Update right highest if current bar is taller
                else 
                    ans += rhd - a[j]; // Water trapped is difference between right highest and current height
                j--; // Move right pointer backward
            }
        } 

        return ans;
    }
};
