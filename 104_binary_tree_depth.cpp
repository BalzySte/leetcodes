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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> nodes;
        int max_depth = 0;
        
        if (!root)
            return 0;

        nodes.push({root, 1});
        while( !nodes.empty() ) {
            auto [node, depth] = nodes.top();
            nodes.pop();

            max_depth = max(max_depth, depth);

            // order does not really matter here
            if (node->left)
                nodes.push({node->left, depth + 1});
            if (node->right)
                nodes.push({node->right, depth + 1});
        }

        return max_depth; 
    }
};
