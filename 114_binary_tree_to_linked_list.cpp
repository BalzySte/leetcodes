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
    void flatten(TreeNode* root) {
        stack<TreeNode*> nodes;

        if (!root)
            return;
        
        auto node = root;

        while ( node ) {
            if (node->left) {
                if (node->right)
                    nodes.push(node->right);

                node->right = node->left;
                node->left = nullptr;
                node = node->right;
                continue;
            }

            if (node->right) {
                node = node->right;
                continue;
            }

            if (nodes.empty()) {
                return;
            }

            node->right = nodes.top();
            nodes.pop();
            node = node->right;
        }
    }
};
