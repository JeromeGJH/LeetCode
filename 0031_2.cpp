class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1){
            return;
        }
        int l = nums.size();
        int i, tmp = 0, left = 0, right = l-1;
        for(i = l-1; i > 0; --i){
            if(nums[i] > nums[i-1]){
                break;
            }
        }
        //std::cout << "flag: " << flag  << std::endl;
        int pivot = i-1;
        if(pivot >= 0){
            for(i = pivot+1; i < l-1; ++i){
                if(nums[i] > nums[pivot] && nums[i+1] <= nums[pivot]){
                    break;
                }
            }
            tmp = nums[i];
            nums[i] = nums[pivot];
            nums[pivot] = tmp;
        }

        left = pivot + 1;
        right = l-1;
        while(left < right){
            tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left += 1;
            right -= 1;
        }
        return;
    }
};
