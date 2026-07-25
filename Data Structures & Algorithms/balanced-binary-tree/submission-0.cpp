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
    bool isBalanced(TreeNode* root) {
        int height {0};
        return balanced(root, height);
    }

    bool balanced(TreeNode* root, int &height) {
        if(!root) return true;

        int leftHeight{0};
        auto left = balanced(root->left, leftHeight);
        if(!left) return false;

        int rightHeight{0};
        auto right = balanced(root->right, rightHeight);
        if(!right) return false;

        if(abs(leftHeight - rightHeight) > 1) return false; 
        height = leftHeight > rightHeight ? leftHeight : rightHeight;
        height++; //current Node;
        return true;
    }

};
