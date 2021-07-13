class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        vector<int> res(l, 0);
        int i = 0, r = 1;
        res[0] = 1;
        for(i = 1; i < l ; ++i){
            res[i] = res[i-1] * nums[i-1];
        }
        for(i = l - 2; i >= 0; --i){
            r *= nums[i+1];
            res[i] = res[i] * r;
        }
        return res;
    }
};
