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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL)return 1;
        int minlh = minDepth(root -> left);
        int minrh = minDepth(root -> right);
        //if left child is null then it there only depth in right dir
        if(root->left == NULL)
            return 1 + minrh;
        //if right child is null then there only depth in left dir
        if(root->right == NULL)
            return 1 + minlh;
        // if both dir have depth then we will take the mini of them
        return 1 + min(minlh, minrh);
    }
};