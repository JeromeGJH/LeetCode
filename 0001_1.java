class Solution {
    public int[] twoSum(int[] nums, int target) {
        int l = nums.length;
        int[] copy = new int[l];
        for(int i = 0; i < l; ++i){
            copy[i] = nums[i];
        }
        Arrays.sort(nums);
        int[] ret = new int[2];
        int L = 0, R = l - 1;
        int sum = 0;
        while(L < R){
            sum = nums[L] + nums[R];
            if(sum == target){
                break;
            }else{
                if(sum < target)
                    ++L;
                else
                    --R;
            }
        }
        int left = nums[L], right = nums[R];
        int i = 0, j = 0;
        for(i = 0; i < l; ++i){
            if(copy[i] == left){
                ret[0] = i;
                while(j < l){
                    if( i == j){
                        ++j;
                        continue;
                    }
                    if(copy[j] == right){
                        ret[1] = j;
                        break;
                    }
                    ++j;
                }
                break;
            }
        }
        return ret;

    }
}
