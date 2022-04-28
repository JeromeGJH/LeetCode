class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n -1 , mid ;
        int i = 0;
        while(left < right){
            mid = (left + right) / 2;
            if(mid > 0 && mid < n-1){
                if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                    return nums[mid];
                }
                if(nums[mid] == nums[mid-1]){
                    if(mid & 1 == 1){
                        left = mid + 1;
                    }
                    else{
                        right = mid - 2;
                    }
                }else{
                    if(mid & 1 == 1){
                        right = mid - 1;
                    }else{
                        left = mid + 2;
                    }
                }
            }else{
                return nums[mid];
            }
        }
        return nums[left];

    }
};
