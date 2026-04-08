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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        res.emplace_back(vector<int>({root->val}));

        auto right = levelOrder(root->right);
        auto left = levelOrder(root->left);
        
        int sz = min(left.size(), right.size());

        for(int i = 0; i < sz; i++) {
            auto l = left[i];
            auto r = right[i];
            l.insert(l.end(), r.begin(), r.end());
            res.emplace_back(l);
        }

        if(sz < right.size()) {
            res.insert(res.end(), right.begin() + sz, right.end());
        }
        if(sz < left.size()) {
            res.insert(res.end(), left.begin() + sz, left.end());
        }
        return res;
    }
};
