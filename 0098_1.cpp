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
    bool checkL(TreeNode* root, int l, int r, bool L, bool R){
        if(root == nullptr){
            return true;
        }
        if(root->val >= r){
            return false;
        }
        if(root->val < l){
            return false;
        }
        if(root->val == l){
            if(L){
                return checkL(root->left, l, l, false, R) && checkR(root->right, l, r, false, R);
            }else{
                return false;
            }
        }
        return checkL(root->left, l, root->val, L, R) && checkR(root->right, root->val, r, L, R);

    }

    bool checkR(TreeNode* root, int l, int r,bool L, bool R){
        if(root == nullptr){
            return true;
        }
        if(root->val <= l){
            return false;
        }
        if(root->val > r){
            return false;
        }
        if(root->val == r){
            if(R){
                return checkL(root->left, l, r, L, false) && checkR(root->right, r, r, L, false);
            }else{
                return false;
            }
        }
        return checkL(root->left, l, root->val, L, R) && checkR(root->right, root->val, r, L, R);
    }

    bool isValidBST(TreeNode* root) {
        cout << INT_MIN<<endl;
        bool L = root->val == INT_MIN? false:true;
        bool R = root->val == INT_MAX? false:true;
        return checkL(root->left, INT_MIN, root->val, L, false) && checkR(root->right, root->val, INT_MAX, false, R);

    }
};
