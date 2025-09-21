class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int n = arr.size();

        // Start from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] < 9) {
                arr[i]++;  // just add 1 and return
                return arr;
            }
            arr[i] = 0; // carry over
        }

        // If all digits were 9 (e.g. 999 + 1 = 1000)
        arr.insert(arr.begin(), 1);
        return arr;
    }
};