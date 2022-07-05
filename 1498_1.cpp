class Solution {
public:
    int mod = 1000000007;
    long fastPow(int _x, int n){
        long res = 1, x= _x;
        while(n > 0){
            if((n & 1)==1) 
                res =(res * x) % mod;
            x = (x * x) % mod;
            n>>=1;
        }
        return res % mod;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        int i = 0, t, left, right, mid;
        long long s = 0;
        for(i = 0; i < l; ++i){
            if(nums[i] + nums[i] > target){
                return (int)s;
            }else{
                t = target - nums[i];
                left = i;
                right = l-1;
                while(left < right){
                    mid = (left + right) / 2 + 1;
                    if(nums[mid] > t){
                        right = mid  - 1;
                    }else{
                        left = mid;
                    }
                }
                
                s += fastPow(2, left - i);
                s %= mod;
            }
        }
        return (int)s;
    }
};
