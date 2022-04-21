class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i, left, right, mid, pivot = 0, n= nums.size(), tmp;
        for(i = 1; i < n; ++i){
            if(nums[i] < nums[i-1]){
                pivot = i;
                break;
            }
        }
        left = pivot;
        right = pivot - 1 + n;
        while(left <= right){
            mid = (left + right)/2;
            tmp = mid%n;
            if(nums[tmp] == target){
                return tmp;
            }
            if(nums[tmp] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
};
