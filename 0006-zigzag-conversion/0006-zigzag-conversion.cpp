class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1)
            return s;

        string ans = "";

        for (int i = 0; i < numRows; i++) {
            int idx = i;
            int south = 2 * (numRows - 1 - i);
            int north = 2 * i;
            bool gsouth = 1;

            while (idx < s.length()) {
                ans.push_back(s[idx]);

                if (i == 0) {
                    idx += south;
                } else if (i == numRows - 1) {
                    idx += north;
                } else {
                    if (gsouth) {
                        idx += south;
                    } else {
                        idx += north;
                    }
                    gsouth = !gsouth;
                }
            }
        }

        return ans;
    }
};