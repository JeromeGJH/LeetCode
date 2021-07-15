class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = nums.size(), i = 0;
        vector<vector<int>> dp(l , vector<int>(2, 0));
        int imax = nums[0], imin = nums[0];
        int ans = imax;
        for(i = 1; i < l; ++i){
            if(nums[i] < 0){
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            ans = max(ans, imax);
        }
        return ans;
    }
};
