class Solution {
    public int maxSubArray(int[] nums) {
        int len = nums.length;
        int j = 0;
        int preMax = 0;
        int max = nums[0];
        for(j = 0; j < len; ++j){
            preMax = preMax <= 0 ? nums[j]:nums[j] + preMax;
            max = Math.max(max, preMax);
        }
        return max;
    }
}
