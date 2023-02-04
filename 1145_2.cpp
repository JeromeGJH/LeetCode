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
    int sumNodes(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        if(node->left == nullptr){
            if(node->right == nullptr){
                return 1;
            }
            else{
                return 1 + sumNodes(node->right);
            }
        }
        else{
            if(node->right == nullptr){
                return 1 + sumNodes(node->left);
            }
            else{
                return 1 + sumNodes(node->left) + sumNodes(node->right);
            }
        }
    }

    bool findNode(TreeNode* node, int n, int x){
        if(node == nullptr){
            return false;
        }
        if(node->val == x){
            int s1 = sumNodes(node->left);
            int s2 = sumNodes(node->right);
            int s = s1 + s2 + 1;
            if(s <= n/2){
                return true;
            }else{
                if(s1 > n/2 || s2 > n/2){
                    return true;
                }
            }
            return false;
        }else{
            return findNode(node->left, n, x)||findNode(node->right, n, x);
        }
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        return findNode(root, n, x);
    }
};
