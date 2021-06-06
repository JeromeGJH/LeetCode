class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int l = nums.length;
        int[][] dp = new int[l][l];;
        int i, j;
        int max = nums[0];
        for( i = 0; i < l; ++i){
            dp[i][0] = nums[i];
            for( j = 1; j < l; ++j){
                dp[i][j] = dp[i][j-1] <= 0? nums[(j + i)%l]: nums[(i + j)%l] + dp[i][j-1];
                if(max < dp[i][j])
                    max = dp[i][j];
            }
        }
        return max;
    }
}
