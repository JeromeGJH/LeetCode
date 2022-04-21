class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i, left, right, mid, pivot = 0, n= nums.size(), tmp;
        left = 0;
        right = n-1;
        if(nums[0] == target){
            return 0;
        }
        while(left <= right){
            mid = (left + right)/2;
            if(target == nums[mid]){
                return mid;
            }
            if(nums[0] <= nums[mid]){
                if(nums[0] <= target && target < nums[mid]){
                    right= mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(nums[mid] < target && target < nums[0]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }

            }
        }
        return -1;
    }
};
