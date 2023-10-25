class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int pre = nums[0];
        int cur;
        int i  = 0;
        int ans = pre;
        for(i = 1; i < len; ++i){
            cur = max(0, pre) + nums[i];
            ans = max(ans, cur);
            pre = cur;
        }
        return ans;
    }
};
