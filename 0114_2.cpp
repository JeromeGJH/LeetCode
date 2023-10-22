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
    void flatten(TreeNode* root) {
        while(root){
            if(!root->left){
                root = root->right;

            }else{
                TreeNode * node = root->left;
                while(node->right){
                    node = node->right;
                }
                node->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;

            }

        }
        return;


    }
};
