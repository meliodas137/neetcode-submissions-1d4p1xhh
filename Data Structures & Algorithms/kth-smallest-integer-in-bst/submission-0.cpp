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
    void flatten(TreeNode* root, vector<int> &res){
        if(root == NULL) return;
        flatten(root->left, res);
        res.emplace_back(root->val);
        return flatten(root->right, res);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> flat;

        flatten(root, flat);

        return flat[k-1];
    }
};
