/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        auto clonedNode = new Node(node->val);
        unordered_map<int, Node*> dict;

        dict[node->val] = clonedNode;

        clone(clonedNode, dict, node);
        return clonedNode;
    }

    void clone(Node* n1, unordered_map<int, Node*> &dict, Node* n2) {
        for(auto &n: n2->neighbors) {
            if(dict.find(n->val) == dict.end()) {
                dict[n->val] = new Node(n->val);
                clone(dict[n->val], dict, n);
            }
            (n1->neighbors).emplace_back(dict[n->val]);
        }
        return;
    }
};
