class Solution {
    public int lengthOfLIS(int[] nums) {
        int l = nums.length;
        int length = 1;
        int[] dp = new int[l];
        int i, j;
        for(i = 0; i< l; ++i){
            dp[i] = 1;
            for(j = 0; j < i; ++j){
                if( nums[i] > nums[j]){
                    dp[i] = Math.max(dp[i], dp[j]+1);
                }
            }
        }
        for(i = 0; i< l; ++i){
            length = Math.max(length, dp[i]);
        }
        return length;
    }
}
