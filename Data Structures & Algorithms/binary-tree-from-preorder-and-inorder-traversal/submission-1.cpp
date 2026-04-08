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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        TreeNode* head = new TreeNode(preorder[0]);
        head->left = NULL;
        head->right = NULL;
        if(preorder.size() == 1) return head;

        int in_idx = 0;

        for(auto &n: inorder) {
            if(n == preorder[0]) break;
            in_idx++;
        }

        vector<int> lpre, rpre, lin, rin;

        lin = vector<int>(inorder.begin(), inorder.begin()+in_idx);
        rin = vector<int>(inorder.begin()+in_idx+1, inorder.end());

        if(lin.empty()) {
            auto pre = vector<int>(preorder.begin()+1, preorder.end());
            head->left = NULL;
            head->right = buildTree(pre, rin);
            return head;
        }
        if(rin.empty()) {
            auto pre = vector<int>(preorder.begin()+1, preorder.end());
            head->right = NULL;
            head->left = buildTree(pre, lin);
            return head;
        }

        in_idx = 0;
        for(auto &n: preorder) {
            if(n == rin[0]) break;
            in_idx++;
        }

        lpre = vector<int>(preorder.begin()+1, preorder.begin()+lin.size()+1);
        rpre = vector<int>(preorder.begin()+lin.size()+1, preorder.end());

        head->left = buildTree(lpre, lin);
        head->right = buildTree(rpre, rin);
        return head;
        
    }
};
