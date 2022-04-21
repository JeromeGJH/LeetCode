class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 1, right = nums.size() - 1, mid;
        while(left <= right){
            mid = (left + right)/2;
            if(nums[mid] < nums[0]){
                if(nums[mid-1] < nums[mid]){
                    right = mid - 1;
                }else{
                    return nums[mid];
                }
                
            }else{
                left = mid + 1;
            }
        }
        return nums[0];
    }
};
