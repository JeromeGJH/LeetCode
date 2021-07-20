class Solution {
    public int maxSizeSlices(int[] slices) {
        int l = slices.length;
        if(l == 3){
            return Math.max(slices[0], Math.max(slices[1], slices[2]));
        }
        int n = l/3;
        int i = 0, j = 1;
        int[][] dp = new int[l][n + 1];
        dp[0][0] = 0;
        dp[0][1] = slices[0];
        dp[1][0] = 0;
        dp[1][1] = Math.max(slices[1], slices[0]);
        int max = 0;
        for(i = 2; i < l - 1; ++i){
            dp[i][0] = 0;
            j = 1;
            while(j <= n){
                dp[i][j] = Math.max(dp[i - 2][j - 1] + slices[i], dp[i - 1][j]);
                max = Math.max(max, dp[i][j]);
                ++j;
            }
        }
        int[][] dp1 = new int[l][n + 1];
        
        dp1[1][0] = 0;
        dp1[2][0] = 0;
        dp1[1][1] = slices[1];
        dp1[2][1] = Math.max(slices[1], slices[2]);

        for(i = 3; i < l; ++i){
            dp1[i][0] = 0;
            j = 1;
            while(j <= n){
                dp1[i][j] = Math.max(dp1[i - 2][j - 1] + slices[i], dp1[i - 1][j]);
                max = Math.max(max, dp1[i][j]);
                ++j;
            }
        }

        return max;
    }
} 
