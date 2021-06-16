class Solution {
public:
    vector<int> countBits(int n) {
        int i = 0;
        int count = 0;
        vector<int> res(n+1, 0);
        for(i = 0; i <= n; ++i){
            count = 0;
            int tmp = i;
            while(tmp > 1){
                count += tmp % 2;
                tmp /= 2;
            }
            count += tmp;
            res[i] = count;
        }
        return res;

    }
};
