class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        if(x <= 3){
            return 1;
        }
        int l = 1, r = x/2;
        long m;
        long res;
        while(l < r){
            m = (l+r)/2 + 1;
            res = m * m;
            if(res > x){
                r = m-1;
            }else{
                if(res == x){
                    return m;
                }else{
                    l = m;
                }
            }
        }
        return l;
    }
};
