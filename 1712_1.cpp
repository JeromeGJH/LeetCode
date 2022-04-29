class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int mod = 1e9 + 7, n = nums.size(), i, left, right, mid, p1;
        long res = 0;
        
        vector<int> sums(n, 0);
        sums[0] = nums[0];

        for(i = 1; i < n; ++i){
            sums[i] = sums[i-1] + nums[i];
        }

        for(i = 0; i < n - 2; ++i){
            left = i + 1;
            right = n - 2;
            while(left < right){
                mid = (left + right) / 2;
                if(sums[mid] < sums[i] << 1){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            p1 = left;
            if(sums[p1] < sums[i] << 1){
                continue;
            }

            left = p1;
            right = n-2;
            while(left < right){
                mid = (left + right) / 2 + 1;
                if(sums[n-1] + sums[i] >= sums[mid] << 1){
                    left = mid;
                }else{
                    right = mid - 1;
                }
            }
            if(sums[i] + sums[n-1] < sums[left] << 1){
                continue;
            }else{
                res += left - p1 + 1;
            }
        }
        return res % mod;
    }
};
