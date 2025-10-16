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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        // tuple< Node ptr, depth, partial_number >
        stack<tuple<TreeNode*, int, int>> nodes;

        if (!root)
            return 0;
        
        nodes.push({root, 0, 0});

        while (!nodes.empty()) {
            auto [node, depth, number] = nodes.top();
            nodes.pop();
            number = number * 10 + node->val;

            if (node->left) nodes.push({node->left, depth + 1, number});
            if (node->right) nodes.push({node->right, depth + 1, number});

            if (!node->left && !node->right) {
                sum += number;
            }
        }
    
        return sum;   
    }
};
