class Solution {
public:
    void exchange(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        return;
    }

    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1){
            return;
        }
        int l = nums.size();
        int i, d = 0, tmp, flag = 0, left = 0, right = l-1;
        for(i = l-1; i > 0; --i){
            if(nums[i] > nums[i-1]){
                flag = 1;
                break;
            }
        }
        //std::cout << "flag: " << flag  << std::endl;
        
        if(flag == 0){
            d = 0;
            left = 0;
            right = l-1;
            while(left < right){
                exchange(nums, left, right);
                //std::cout << "i: " << i << " " << nums[i] << std::endl;
                //std::cout << "j: " << j << " " << nums[j] << std::endl;
                left += 1;
                right -= 1;
            }
            //std::cout << "here1" << std::endl;
            //std::cout << nums[0] << std::endl;
            return;
        }
        
        int pivot = i-1;
        //std::cout << "i: " << i << " " << nums[i] << std::endl;
        if(pivot + 2 == l){
            exchange(nums, pivot, pivot + 1);
            //std::cout << "here1" << std::endl;
            return;
        }

        for(i = pivot+1; i < l-1; ++i){
            if(nums[i] > nums[pivot] && nums[i+1] <= nums[pivot]){
                break;
            }
        }
        exchange(nums, i, pivot);
        left = pivot + 1;
        right = l-1;
        while(left < right){
            exchange(nums, left, right);
            left += 1;
            right -= 1;
        }
        return;
    }
};
