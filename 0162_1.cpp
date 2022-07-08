class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int m = nums.size() - 1;
        if(m == 0){
            return 0;
        }
        int left = 0, right = m, mid = 0;
        while(left < right){
            mid = (left + right) / 2;
            if(mid == 0 && nums[1] < nums[0]){
                return mid;
            }
            if(mid == m && nums[m] > nums[m-1]){
                return mid;
            }
            if(nums[mid] < nums[mid+1]){
                left = mid + 1;
            }else{
                if(nums[mid] > nums[mid-1]){
                    return mid;
                }else{
                    right = mid - 1;
                }
            }
            
        }
        return left;

    }
};
