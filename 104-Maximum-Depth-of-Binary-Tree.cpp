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
        if(root == NULL) return 0;
        int leftDepth = maxDepth(root -> left);
        int rightDepth = maxDepth( root -> right);

        // after going to extreme left leftDepth will return 0
        // as well as rightdepth will return 0;
        // now we are standing at the last leaf node 
        // from here we have to return 1 
        // likewise from any middle node we have to return the max of lh and rh by adding + 1;
        return 1 + max(leftDepth , rightDepth);
    }
};