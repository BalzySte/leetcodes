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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> p_nodes, q_nodes;
        TreeNode* p_node = p;
        TreeNode* q_node = q;

        // same object or empty trees
        if (p == q || (p == nullptr && q == nullptr))
            return true;
        
        while(true) {
            if (p_node) {
                if ( !q_node || q_node->val != p_node->val ) {
                    return false;
                }
            } else {
                if (q_node)
                    return false;

                while ( !p_node && !p_nodes.empty() ) {
                    p_node = p_nodes.top();
                    p_nodes.pop();

                    if (q_nodes.empty())
                        return false;
                    
                    q_node = q_nodes.top();
                    q_nodes.pop();
                }

                if ( !p_node && !q_node ) {
                    break;
                }

                continue;
            }

            p_nodes.push(p_node->right);
            p_node = p_node->left;
            q_nodes.push(q_node->right);
            q_node = q_node->left;
        }

        return true;
    }
};

// NOTE: can be simplified by keeping a pair <p_node, q_node> in the stack
//       and pushing both left and right child nodes, one after the other.
//       std::stack<std::pair<TreeNode*, TreeNode*>> st;
