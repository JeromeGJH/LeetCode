class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        if(l == 0){
            return l;
        }
        int i = 0;
        int total = 0;
        int count = 1;
        int pivot = 0;
        int pre = nums[0];
        for(i = 1; i < l; ++i){
            if(total > 0){
                nums[i-total] = nums[i];
            }
            if(nums[i] == pre){
                count += 1;
                if(count > 2){
                    total += 1;
                }
            }else{
                count = 1;
            }
            pre = nums[i];
        }
        nums.erase(nums.end()-total, nums.end());
        return l-total;

        

    }
};
