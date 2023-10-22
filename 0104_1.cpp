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
    int depth(TreeNode* root){
        if(root->left == nullptr){
            if(root->right == nullptr){
                return 1;
            }else{
                return 1 + depth(root->right);
            }
        }else{
            if(root->right == nullptr){
                return 1 + depth(root->left);
            }else{
                return 1 + max(depth(root->left), depth(root->right));
            }
        }
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return depth(root);

    }
};
