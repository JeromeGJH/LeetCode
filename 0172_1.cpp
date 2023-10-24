class Solution {
public:
    int trailingZeroes(int n) {
        int i = 0;
        int res, ans = 0;
        int num = 5;
        
        while(n >= num){
            res = n/num;
            ans += res;
            num *= 5;
        }
        return ans;

    }
};
