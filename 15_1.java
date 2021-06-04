class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List res = new ArrayList();
        int l = nums.length;
        if(l < 3){
            return res;
        }
        int i = 0, j = 0, k = 0;
        for(i = 0; i < l-2; i++){
            for(j = i + 1; j<l-1; j++){
                for(k = j+1; k < l; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        List tmp = new ArrayList();
                        int a =0, b = 0, c = 0;
                        if(nums[i] <= nums[j]){
                            if(nums[i] <= nums[k]){
                                a = nums[i];
                                if(nums[j] <= nums[k]){
                                    b = nums[j];
                                    c = nums[k];
                                }
                                else{
                                    b = nums[k];
                                    c = nums[j];
                                }
                            }else{
                                a = nums[k];
                                b = nums[i];
                                c = nums[j];
                            }
                        }else{
                            if(nums[j] <= nums[k]){
                                a = nums[j];
                                if(nums[i] <= nums[k]){
                                    b =nums[i];
                                    c = nums[k];
                                }else{
                                    b = nums[k];
                                    c = nums[i];
                                }
                            }else{
                                a = nums[k];
                                b = nums[j];
                                c = nums[i];
                            }
                        }
                        tmp.add(a);
                        tmp.add(b);
                        tmp.add(c);
                        if(!res.contains(tmp))
                            res.add(tmp);
                    }
                }
            }
        }
        return res;

    }
}
