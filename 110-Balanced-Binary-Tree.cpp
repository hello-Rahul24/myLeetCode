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
 //THIS IS O(N2) SOLUTION
// class Solution {
// private:
//     int depth( TreeNode* root){
//         if(root == NULL)return 0;
//         int lh = depth(root ->left);
//         int rh = depth(root -> right);
//         return 1 + max(rh,lh);
//     }
// public:
//     bool isBalanced(TreeNode* root) {
//         // Balanced = at every node, left height and right height differ by at most 1.
//         if(root == NULL) return true;
        
//         bool left = isBalanced(root -> left);
//         bool right = isBalanced(root -> right);
//         bool current = (abs(depth(root-> left) - depth(root ->right)) <= 1);
//         return (left && right && current);

//     }
// };
// THIS IS BETTER INTERVIEW APPROACH
class Solution {
public:
    int heightofBT(TreeNode* root){
        if(root == nullptr) return 0;
        int lh = heightofBT(root -> left);
        if(lh == -1) return -1;
        int rh = heightofBT(root -> right);
        if(rh == -1) return -1;
        if(abs(lh - rh) > 1)return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        int val = heightofBT(root);
        return val != -1;
    }
};