class Solution {
public:
    //int findClosest(int mid){}
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),  d;
        long sum = 0, res;
        int mod = 1e9 + 7;
        vector<int> diff(n, 0);

        vector<int> sorted(nums1);
        sort(sorted.begin(), sorted.end());
        
        int i;
        for(i = 0; i < n; ++i){
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
        }
        res = sum;

        for(i = 0; i < n; ++i){
            if(diff[i] == 0){
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
                res = min(res, sum - diff[i]);
            }else{
                if(right > 0){
                    d = min(abs(sorted[right] - nums2[i]), abs(sorted[right - 1] - nums2[i]));
                }else{
                    d = abs(sorted[right] - nums2[i]);
                }
                res = min(res, sum - diff[i] + d);
            }
        }
        return res % mod;
    }
};
