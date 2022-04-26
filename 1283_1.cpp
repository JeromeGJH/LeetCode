class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int sum = 0, left = 1, right = *max_element(nums.begin(), nums.end()), mid;
        int i, n= nums.size(), count;
        while(left < right){
            mid = (left + right) / 2;
            count = 0;
            for(i = 0; i < n; ++i){
                count += (nums[i] - 1) / mid + 1;
            }
            if(count > threshold){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
