class Solution {
public:
    int calPoints(vector<string>& oprtn) {
        vector<int> stk;

        for (auto& op : oprtn) {
            if (op == "+") {
                int n = stk.size();
                stk.push_back(stk[n - 1] + stk[n - 2]);
            }
            else if (op == "D") {
                stk.push_back(2 * stk.back());
            } 
            else if (op == "C") {
                stk.pop_back();
            } 
            else {
                stk.push_back(stoi(op));
            }
        }

        int sum = 0;
        for (int x : stk) {
            sum += x;
        }
        return sum;
    }
};
