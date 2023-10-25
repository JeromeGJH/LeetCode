class Solution {
public:
    int ans = -1;
    void check(vector<int>& nums, int l, int r){
        if(ans >= 0 || l > r){
            return;
        }
        int mid = (l + r)/2;
        //cout << mid << endl;
        if(mid == nums.size()-1){
            if(nums[mid] > nums[mid-1]){
                ans = mid;
            }else{
                check(nums, l, mid-1);
            }
            return;
        }

        if(mid == 0){
            if(nums[mid] > nums[mid+1]){
                ans = mid;
            }else{
                check(nums, mid+1, r);
            }
            return;
        }

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            ans = mid;
        }else{
            check(nums, l, mid-1);
            check(nums, mid+1, r);
        }
        return;
    }

    int findPeakElement(vector<int>& nums) {
        int len =  nums.size();
        if(len == 1){
            return 0;
        }
        int l = 0, r = len - 1;
        check(nums, 0, len-1);
        return ans;
    }
};
