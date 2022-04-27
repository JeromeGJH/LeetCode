class Solution {
public:
    auto check(int day, int m, int k, vector<int>& bloomDay){
        int i, j, count = 0, flw = 0, n = bloomDay.size();
        vector<bool> state(n+1, false);
        for(i = 0; i < n; ++i){
            if(day >= bloomDay[i]){
                state[i] = true;
            }
        }
        for(i = 0; i < n; ++i){
            while(state[i]){
                ++flw;
                ++i;
            }
            
            if(flw > 0){
                count += flw / k;
                flw = 0;
            }
            
            if(count >= m){
                return true;
            }
        }
        return false;

    };


    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m * k > n){
            return -1;
        }

        int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end()), mid, i;
        while(left < right){
            mid = (left + right) / 2;
            if(check(mid, m, k, bloomDay)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return right;
    }
};
