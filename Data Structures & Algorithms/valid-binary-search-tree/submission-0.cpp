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
    int treeMin(TreeNode* node) {
        if(node == NULL) return INT_MAX;
        if(node->left == NULL && node->right == NULL) return node->val;

        return min(node->val, min(treeMin(node->left), treeMin(node->right)));
    }

    int treeMax(TreeNode* node) {
        if(node == NULL) return INT_MIN;
        if(node->left == NULL && node->right == NULL) return node->val;

        return max(node->val, max(treeMax(node->left), treeMax(node->right)));
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        auto lmin = treeMax(root->left);
        auto rmin = treeMin(root->right);

        if(lmin < root->val && rmin > root->val) return (isValidBST(root->left) && isValidBST(root->right));
        return false;
    }
};
