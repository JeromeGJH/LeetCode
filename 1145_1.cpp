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
    int findNodes(TreeNode* node, vector<int>& v, int n, int x){
        int s = 0;
        if(node->left == nullptr){
            if(node->right == nullptr){
                s = 1;
            }
            else{
                s = 1 + findNodes(node->right, v, n, x);
            }
        }
        else{
            if(node->right == nullptr){
                s = 1 + findNodes(node->left, v, n, x);
            }
            else{
                s = 1 + findNodes(node->left, v, n, x) + findNodes(node->right, v, n, x);
            }
        }
        v[node->val] = s;
        if(node->val == x){
            if(v[x] <= n/2){
                v[0] = 1;
            }else{
                if(v[node->left->val] > n/2 || v[node->right->val] > n/2){
                    v[0] = 1;
                }else{
                    v[0] = 0;
                }
            }
        }
        return s;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<int> node = vector<int>(n+1,0);
        findNodes(root, node, n, x);
        
        return node[0] == 1;
    }
};
