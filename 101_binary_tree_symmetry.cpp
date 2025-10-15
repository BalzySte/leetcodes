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
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> deq;

        if (!root)
            return true;

        deq.push_front(root->left);
        deq.push_front(root->right);

        while(!deq.empty()) {
            // pop left-most and right-most items
            auto left = deq.back();
            auto right = deq.front();
            deq.pop_back();
            deq.pop_front();

            // compare the items
            // either both are nullptr or they store the same value
            if (left && right) {
                if (left->val != right->val)
                    return false;
            } else if (!left && !right)
                continue;
            else
                return false;

            // push the child nodes left and right
            deq.push_back(left->right);
            deq.push_back(left->left);
            deq.push_front(right->left);
            deq.push_front(right->right);
        }
        
        return true;
    }
};
