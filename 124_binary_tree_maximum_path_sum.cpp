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
    int maxPathSum(TreeNode* root) {
        // list of nodes, level order from the root
        vector<TreeNode*> nodes_vector;
        // hashmap of maximum downward sum from a node
        unordered_map<TreeNode*, int> max_down_map;

        if (!root)
            return 0;

        nodes_vector.push_back(root);

        // populate the list of nodes
        for (size_t i = 0; i < nodes_vector.size(); ++i) {
            auto node = nodes_vector[i];
            if (node->left) nodes_vector.push_back(node->left);
            if (node->right) nodes_vector.push_back(node->right);
        }

        int best_path_sum = INT_MIN;
        max_down_map.reserve(nodes_vector.size());
        max_down_map[nullptr] = 0;

        for (int i = nodes_vector.size() - 1; i >= 0; --i) {
            auto node = nodes_vector[i];
            // maximum downward contribution a node can give to it's parent
            int max_down;
            // maximum path sum through the node (candidate best path sum)
            // (the path that uses this node as highest point)
            int through_sum;

            int left_down = max_down_map[node->left];
            int right_down = max_down_map[node->right];
            left_down = max(left_down, 0);
            right_down = max(right_down, 0);

            max_down = node->val + max(left_down, right_down);
            through_sum = node->val + left_down + right_down;

            max_down_map[node] = max_down;
            best_path_sum = max(best_path_sum, through_sum);
        }

        return best_path_sum;
    }
};

// NOTE: this algorithm is sub-optimal and can be further improved.
//       While complexity is already O(n), a solution based on post-order
//       traversal avoids the overhead of a hashtable and allows to find
//       the maximum path sum in one scan.
