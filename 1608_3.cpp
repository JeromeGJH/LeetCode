class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int mid = (left + right)/2;
        int res = nums.size() - mid;

        while(left < right){
            //cout << left << " " << right << " " << mid << endl;
            if(nums[mid] >= res){
                right = mid;
            }else{
                left = mid + 1;
            }
            mid = (left + right)/2;
            res = nums.size() - mid;
        }

        if((left == 0 || nums[left-1] < res) && nums[left] >= res){
            return res;
        }

        return -1;
    }
};
