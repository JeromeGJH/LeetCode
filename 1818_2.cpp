class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), d, i;
        long sum = 0, res;
        int mod = 1e9 + 7;

        vector<int> sorted(nums1);
        sort(sorted.begin(), sorted.end());
        
        for(i = 0; i < n; ++i){
            sum += abs(nums1[i] - nums2[i]);
        }
        res = sum;

        for(i = 0; i < n; ++i){
            if(nums1[i] == nums2[i]){
                continue;
            }
            int left = 0, right = n-1, mid;
            while(left < right){
                mid = (left + right) / 2;
                if(sorted[mid] >= nums2[i]){
                    right = mid;
                }else{
                    left = mid + 1;
                }
            }
            if(sorted[right] == nums2[i]){
                res = min(res, sum - abs(nums1[i] - nums2[i]));
            }else{
                d = right > 0 ? min(abs(sorted[right] - nums2[i]), abs(sorted[right - 1] - nums2[i])) :abs(sorted[right] - nums2[i]);
                res = min(res, sum - abs(nums1[i] - nums2[i]) + d);
            }
        }
        return res % mod;
    }
};
