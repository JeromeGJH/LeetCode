class Solution {
    public int rob(int[] nums) {
        int  l = nums.length;
        if(l == 1)
            return nums[0];
        if(l == 2)
            return Math.max(nums[0], nums[1]);
        if(l == 3){
            return Math.max(nums[0], Math.max(nums[1], nums[2]));
        }
        int max1 , max2;
        int[] dp1 = new int[l];
        int[] dp2 = new int[l];
        int i = 2;
        dp1[0] = nums[0];
        dp1[1] = dp1[0];
        max1 = dp1[1];
        for(i = 2; i < l-1; ++i){
            dp1[i] = Math.max(dp1[i-2] + nums[i], dp1[i-1]);
            max1 = Math.max(max1, dp1[i]);
        }
        dp2[0] = 0;
        dp2[1] = nums[1];
        max2 = dp2[1];
        for( i = 2; i < l; ++i){
            dp2[i] = Math.max(dp2[i-2] + nums[i], dp2[i-1]);
            max2 = Math.max(max2, dp2[i]);
        }

        return Math.max(max1, max2);
    }
}
