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
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL && root == NULL) return true;
        if(subRoot == NULL || root == NULL) return false;
        return (root->val == subRoot->val && isSame(root->right, subRoot->right) && isSame(root->left, subRoot->left));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL && root == NULL) return true;
        if(subRoot == NULL || root == NULL) return false;

        return ((root->val == subRoot->val && isSame(root, subRoot)) ||
                isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot)) ;
    }
};
