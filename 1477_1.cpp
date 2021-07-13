class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l = arr.size(), i = 0;
        if(l == 1){
            return -1;
        }
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        vector<int> dp(l, 0);
        vector<int> dp2(l, 0);
        vector<int> L(l, 0);
        vector<int> R(l, 0);
        int min1 = INT_MAX, min2 =INT_MAX, tmp;
        //cout << "here2";
        for(i = 0; i < l ; ++i){
            //cout<< i;
            sum += arr[i];
            //cout << "here3";
            if(mp.count(sum - target)){
                tmp = i - mp[sum - target];
                dp[i] = tmp;
                dp2[mp[sum - target]+1] = tmp;
            }
            mp[sum] = i;
            
        }
        //cout << "here1";
        for(i = 1; i <= l-2 ; ++i){
            if(dp[i-1] > 0){
                if(dp[i-1] < min1){
                    min1 = dp[i-1];
                }
            }
            L[i] = min1;
        }
        for(i = l-1; i >= 1 ; --i){
            if(dp2[i] > 0){
                if(dp2[i] < min2){
                    min2 = dp2[i];
                }
            }
            R[i] = min2;
        }

        int res = INT_MAX;
        for(i = 1; i <= l-2; ++i){
            if(L[i] < INT_MAX && R[i] < INT_MAX){
                res = min(res, L[i] + R[i]);
            }
        }
        // for( i = 0; i < l ;++i){
        //     cout << "i: "<<i << "  "<<dp[i] <<"   "<< dp2[i]<< endl;
        // }



        if(res < INT_MAX){
            return res;
        }
        return -1;

    }
};
