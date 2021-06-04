class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int l = nums.length;
        if(l < 3){
            return res;
        }else{
            Arrays.sort(nums);
            int L, R;
            for(int i = 0;i < l-2;++i){
                if(nums[i] > 0) break;
                if(i > 0 && nums[i] == nums[i-1])
                    continue;
                L = i + 1;
                R = l - 1;
                while(L < R){
                    if(nums[R] < 0) break;
                    int sum = nums[i] + nums[L] + nums[R];
                    if(sum == 0){
                        List<Integer> tmp = new ArrayList<>();
                        tmp.add(nums[i]);
                        tmp.add(nums[L]);
                        tmp.add(nums[R]);
                        res.add(tmp);
                        while(L < R && nums[L] == nums[L + 1]) ++L;
                        while(L < R && nums[R] == nums[R - 1]) --R;
                        ++L;
                        --R;
                    }else{
                        if(sum < 0){
                            L += 1;
                            while(L < R && nums[L] == nums[L - 1]) ++L;
                        }
                        if(sum > 0){
                            R -= 1;
                            while(L < R && nums[R] == nums[R + 1]) --R;
                        }
                    }
                }
            }
            return res;
        }
    }
}

   
