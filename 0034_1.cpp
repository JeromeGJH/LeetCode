class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left <= right){
            mid = (left + right)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                if(nums[mid] > target){
                    right = mid - 1;
                }else{
                    while(right >= mid){
                        if(nums[right] == target){
                            break;
                        }else{
                            --right;
                        }
                    }
                    while(left <= mid){
                        if(nums[left] == target){
                            break;
                        }else{
                            ++left;
                        }
                    }
                    break;

                }
            }
        }
        if(left > right){
            return vector<int>{-1, -1};
        }
        return vector<int>{left, right};

    }
};
