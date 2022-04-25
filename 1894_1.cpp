class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0, n = chalk.size();    
        vector<long> sums(n, 0);
        sums[0] = chalk[0];
        for(i = 1; i < n; ++i){
            sums[i] = sums[i-1] + (long)chalk[i];
        }
        k %= sums[n - 1];
        int left = 0, right = n-1, mid;
        while(left < right){
            mid = (left + right)/2;
            if(sums[mid] <= k){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return right;

    }
};
