#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int longestPath(TreeNode* root) {
    const auto dfs = [&](auto&& dfs, TreeNode* node) -> int {
        if (!node)
            return 0;
        int left = dfs(dfs, node->left);
        int right = dfs(dfs, node->right);

        return std::max({node->val + left, node->val + right, node->val});
    };
}
