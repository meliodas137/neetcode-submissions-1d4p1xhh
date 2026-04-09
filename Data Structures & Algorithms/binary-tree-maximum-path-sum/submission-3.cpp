/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int maxSum(TreeNode* root) {
        if(root == NULL) return INT_MIN;

        auto l = max(maxSum(root->left), 0);
        auto r = max(maxSum(root->right), 0);

        return max(l, r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        if(root == NULL) return INT_MIN;

        auto l = max(maxSum(root->left), 0);
        auto r = max(maxSum(root->right), 0);

        return max(max(maxPathSum(root->left), maxPathSum(root->right)), (l + r + root->val));
    }
};
