class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        unordered_map<int,int> freq;

        for(int i=0; i<arr.size(); i++) {
            freq[arr[i]]++;
        }

        for(auto it : freq) {
            if (it.second > (n/3)) ans.push_back(it.first);
        }

        return ans;


    }
};