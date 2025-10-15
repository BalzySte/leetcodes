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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> nodes;

        if (!root)
            return root;
        
        nodes.push(root);

        while(!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();

            // node->left = node->right;
            swap(node->left, node->right);

            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
        }

        return root;
    }
};
