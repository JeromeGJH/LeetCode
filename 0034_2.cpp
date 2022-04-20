class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid, ans1, ans2;
        if(right == -1){
            return vector<int>{-1, -1};
        }

        while(left < right){
            mid = (left + right)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        if(nums[left] != target){
            return vector<int>{-1, -1};
        }else{
            ans1 = left;
        }

        right = nums.size()-1;
        while(left < right){
            mid = (left + right)/2 + 1;
            if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }
        ans2 = right;
        
        return vector<int>{ans1, ans2};
    }
};
