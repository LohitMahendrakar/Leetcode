class Solution {
public:
    void dfs(TreeNode* node, vector<int>& ans){
        if(node == nullptr) return;
        ans.push_back(node->val);
        dfs(node->left, ans);
        dfs(node->right, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root, ans);
        sort(ans.begin(), ans.end());

        return ans[k-1];
    }
};