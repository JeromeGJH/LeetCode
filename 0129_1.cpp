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
    int calc(TreeNode* root, int pre){
        int cur = pre * 10 + root->val;
        if(!root->left && !root->right){
            return cur;
        }else{
            if(root->left){
                if(root->right){
                    return calc(root->left, cur) + calc(root->right, cur);
                }
                else{
                    return calc(root->left, cur);
                }
            }else{
                return calc(root->right, cur);
            }
            
        }
    }

    int sumNumbers(TreeNode* root) {
        return calc(root, 0);


    }
};
