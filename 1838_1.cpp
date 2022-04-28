class Solution {
public:
    bool check(const vector<int>& nums, const vector<long>& sums, int mid, int k){
        int i;
        long res = (long)nums[mid-1] * (mid-1) - sums[mid-2];
        if( res <= k){
            return true;
        }
        for(i = mid; i < nums.size(); ++i){
            res = (long)nums[i] * (mid-1) - sums[i-1] + sums[i-mid];
            if( res <= k){
                return true;
            }
        }
        return false;
    }

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n =  nums.size(), i;
        vector<long> sums(n, 0);
        sums[0] = nums[0];
        for(i = 1; i < n; ++i){
            sums[i] = sums[i-1] + nums[i];
        }

        int left = 1, right = n, mid;
        while(left < right){
            mid = (left + right) / 2 + 1;
            if(check(nums, sums, mid, k)){
                left = mid;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};
