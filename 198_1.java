class Solution {
    public int rob(int[] nums) {
        int l =nums.length;
        if(l == 1){
            return nums[0];
        }
        int[] dp = new int[l];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        if(l == 2){
            return dp[1];
        }
        int max = dp[0];
        for(int i = 2; i< l;++i){
            dp[i] = Math.max(dp[i -2] + nums[i], dp[i - 1]);
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}
