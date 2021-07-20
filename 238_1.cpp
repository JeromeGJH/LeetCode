class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        vector<int> dp1(l, 0);
        vector<int> dp2(l, 0);
        vector<int> res(l, 0);
        int i = 0;
        dp1[0] = nums[0];
        dp2[l-1] = nums[l-1];
        for(i = 1; i < l-1 ; ++i){
            dp1[i] = dp1[i-1] * nums[i];
        }
        for(i = l-2; i > 0; --i){
            dp2[i] = dp2[i+1] * nums[i];
        }
        res[0] = dp2[1];
        res[l-1] = dp1[l-2];
        for(i = 1; i < l-1;++i){
            res[i] = dp1[i-1]*dp2[i+1];
        }
        return res;

    }
};
