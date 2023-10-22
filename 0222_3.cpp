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
    int count(TreeNode* root){
        if(!root->left && !root->right){
            return 1;
        }
        if(root->left){
            if(root->right){
                return 1 + count(root->left) + count(root->right);
            }else{
                return 1 + count(root->left);
            }
        }else{
            return 1 + count(root->right);
        }
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int sum = count(root);
        //cout << sum <<endl;
        //int l = 0;
        // while(sum >= 0){
        //     l += 1;
        //     if(sum == 0){
        //         break;
        //     }
        //     sum = sum / 2;
        // }
        return sum;

    }
};
