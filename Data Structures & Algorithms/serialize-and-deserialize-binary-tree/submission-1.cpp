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

class Codec {
public:
    void inorder_traverse(TreeNode* root, vector<int>& inorder) {
        if(root == NULL) return;
        inorder_traverse(root->left, inorder);
        inorder.emplace_back(root->val);
        inorder_traverse(root->right, inorder);
        return;
    }

    void preorder_traverse(TreeNode* root, vector<int>& preorder) {
        if(root == NULL) return;
        preorder.emplace_back(root->val);
        preorder_traverse(root->left, preorder);
        preorder_traverse(root->right, preorder);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> inorder, preorder;
        
        inorder_traverse(root, inorder);
        preorder_traverse(root, preorder);
        string s;
        for(auto &n: inorder){
            s += to_string(n);
            s += ',';
        }

        s+=':';
        for(auto &n: preorder){
            s += to_string(n);
            s+= ',';
        }

        return s;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        TreeNode* head = new TreeNode(preorder[0]);
        if(preorder.size() == 1) return head;

        int in_idx = 0;

        // for(auto &n: inorder) {
        //     if(n == preorder[0]) break;
        //     in_idx++;
        // }

        
        for(int i = inorder.size() - 1; i >=0; i--) {
            if(inorder[i] == preorder[0]) {
                in_idx = i;
                break;
            }
        }

        vector<int> lpre, rpre, lin, rin;

        lin = vector<int>(inorder.begin(), inorder.begin()+in_idx);
        rin = vector<int>(inorder.begin()+in_idx+1, inorder.end());

        lpre = vector<int>(preorder.begin()+1, preorder.begin()+lin.size()+1);
        rpre = vector<int>(preorder.begin()+lin.size()+1, preorder.end());

        head->left = buildTree(lpre, lin);
        head->right = buildTree(rpre, rin);
        return head;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> inorder, preorder;
        int type = 0;
        cout<<data;
        for(int i = 0; i < data.size(); i++) {
            string str = "";
            for(int j = i; j < data.size(); j++) {
                if(data[j] == ',') break;
                if(data[j] == ':') {type = 1; break;}
                str += data[j]; 
            }
            i += str.size();
            if(str != ""){
                if(type == 0) inorder.emplace_back(stoi(str));
                else preorder.emplace_back(stoi(str));
            }
        }

        return buildTree(preorder, inorder);
    }
};
