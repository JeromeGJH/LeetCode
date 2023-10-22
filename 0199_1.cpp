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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        vector<TreeNode*> cur;
        vector<TreeNode*> nex;
        cur.emplace_back(root);
        int i = 0;     
        while(i < cur.size()){
            if(cur[i]->left){
                nex.emplace_back(cur[i]->left);
            }
            if(cur[i]->right){
                nex.emplace_back(cur[i]->right);
            }
            if(i == cur.size()-1){
                res.emplace_back(cur[i]->val);
                cur = nex;
                nex = vector<TreeNode*>();
                i = 0;
                continue;
            }
            ++i;
        }
        return res;
        

    }
};
