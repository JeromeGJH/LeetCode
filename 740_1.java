class Solution {
    public int deleteAndEarn(int[] nums) {
        int l = nums.length;
        if(l == 1)
            return nums[0];
        Arrays.sort(nums);
        int[][] dp =  new int[l][2];
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        int i = 1, j = 0;
        while(i < l){
            if(nums[i] == nums[i -1]){
                dp[j][0] += nums[i];
            }else{
                ++j;
                dp[j][0] = nums[i];
                dp[j][1] = nums[i] == nums[i - 1] + 1? 1:0;
            }
            ++i;
        }
        int length = j + 1;
        int[] maxsum = new int[length];
        maxsum[0] = dp[0][0];
        if(dp[1][1] == 0){
            maxsum[1] = maxsum[0] + dp[1][0];
        }else{
            maxsum[1] = Math.max(dp[0][0], dp[1][0]);
        }
    
        int max = maxsum[1];
        for(i = 2; i < length; ++i){
            if(dp[i][1] == 0){
                maxsum[i] = maxsum[i-1] + dp[i][0];
            }else{
                maxsum[i] = Math.max(maxsum[i - 2] + dp[i][0], maxsum[i - 1]);
            }
            max = Math.max(max, maxsum[i]);
        }
        return max;


    }
}
