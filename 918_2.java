class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int l = nums.length;
        if( l == 1)
        return nums[0];
        int[] dp = new int[l];
        dp[0] = nums[0];
        int i;
        int min = nums[1];
        int max = nums[0];
        int sum = nums[0];
        for(i = 1; i < l; ++i){
            sum += nums[i];
            dp[i] = dp[i-1] <= 0? nums[i] : nums[i] + dp[i-1];
            if(max < dp[i])
            max = dp[i];
        }
        dp[1] = nums[1];
        for(i = 2; i < l -1; ++i){
            dp[i] = dp[i-1] >= 0? nums[i]: nums[i] + dp[i-1];
            if(min > dp[i])
                min = dp[i];
        }
        max = Math.max(max, sum - min);
        return max;
    }
}
