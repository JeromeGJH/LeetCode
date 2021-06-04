class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int l = nums.length;
        if(l < 3){
            return res;
        }else{
            Arrays.sort(nums);
            //System.out.println(Arrays.toString(nums));
            int i = 0,  j, k = l-1;
            if(nums[0] > 0|| nums[l-1] < 0) 
                return res;
            for(i = 0;i < l-2;++i){
                k = l-1;
                if(nums[i] > 0) break;
                if(i > 0 && nums[i] == nums[i-1])
                    continue;
                for(j = i + 1;j < k ; ++j){
                    if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                    for(k = l-1;k > j ;--k ){
                        if(nums[k] < 0) break;
                        if(k < l-1 && nums[k] == nums[k+1])
                            continue;
                        int sum = nums[i] + nums[j] + nums[k];
                        //System.out.println("sum: " + i + " "+ j +" "+k+" " +sum);
                        if(sum == 0){
                            List<Integer> tmp = new ArrayList<>();
                            tmp.add(nums[i]);
                            tmp.add(nums[j]);
                            tmp.add(nums[k]);
                            res.add(tmp);
                        }
                    }
                    k = l-1;
                }
            }
            return res;
        }
    }
}

   
