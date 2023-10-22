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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        vector<TreeNode*> cur;
        vector<TreeNode*> nex;
        vector<int> nums;
        cur.emplace_back(root);
        int i = 0;
        while(i < cur.size()){
            nums.emplace_back(cur[i]->val);
            if(cur[i]->left){
                nex.emplace_back(cur[i]->left);
            }
            if(cur[i]->right){
                nex.emplace_back(cur[i]->right);
            }
            if(i == cur.size()-1){
                res.emplace_back(nums);
                nums = vector<int>();
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
