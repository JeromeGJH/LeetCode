class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int l = arr.size();
        if(l == 1){
            return 1;
        }

        vector<pair<int, int>> dp(l, pair<int, int>(0, 0));
        vector<pair<int, int>> next(l, pair<int, int>(-1, -1));
        dp[l-1].first = 1;
        dp[l-1].second = 1;
        next[l-1].first = -1;
        next[l-1].second = -1;

        

        int i = 0, j = 0, ans = 0;
        int min_id = -1;
        int max_id = -1;
        int tmp_min = 0, tmp_max = 0;
        


        for(i = l-2; i >= 0; --i){
            min_id = -1;
            max_id = -1;
            tmp_min = INT_MAX;
            tmp_max = -1;
            for(j = i+1; j< l; ++j){
                if(arr[j] >= arr[i] && arr[j] < tmp_min){
                    min_id = j;
                    tmp_min = arr[j];
                }
                if(arr[j] <= arr[i] && arr[j] > tmp_max){
                    max_id = j;
                    tmp_max = arr[j];
                }

            }
            // if(i == 0){
            //     cout << min_id<<endl;
            //     cout << tmp_min<<endl;
            //     cout << max_id<<endl;
            // }
            
            next[i].first = min_id;
            next[i].second = max_id;
            
        }
        cout <<"here";

        int count = 1;
        for(i = l-2; i >= 0; --i){
            // cout <<"i: "<<i << " "<<endl;
            // cout << next[i].first << " " << next[i].second<<endl;
            // cout << dp[i].first << " " << dp[i].second<<endl;
            // cout << i << endl;
            if(next[i].first != -1 && dp[next[i].first].second == 1){
                dp[i].first = 1;
                count += 1;
            }
            if(next[i].second != -1 && dp[next[i].second].first == 1){
                dp[i].second = 1;
            }
        }
        return count;
    }
};
