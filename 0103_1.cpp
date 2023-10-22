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
        bool flag = true;
        while(true){
            if(cur.empty()){
                break;
            }
            if(flag){
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
                    i = cur.size()-1;
                    flag = false;
                    continue;
                }
                ++i;
            }else{
                nums.emplace_back(cur[i]->val);
                if(cur[i]->left){
                    nex.emplace_back(cur[i]->left);
                }
                if(cur[i]->right){
                    nex.emplace_back(cur[i]->right);
                }
                if(i == 0){
                    res.emplace_back(nums);
                    nums = vector<int>();
                    cur = nex;
                    nex = vector<TreeNode*>();
                    i = 0;
                    flag = true;
                    continue;
                }
                --i;
            }
        }
        return res;
    }
};
