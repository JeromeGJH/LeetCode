class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int l = arr.size();
        if(l == 1){
            return 1;
        }

        vector<int> dp(l, 0);
        vector<pair<int, int>> next(l, pair<int, int>(-1, -1));
        //dp[l-1][l-1] = 1;
        next[l-1].first = l-1;
        next[l-1].second = l-1;

        int min_id = -1;
        int max_id = -1;
        int tmp_min = 0, tmp_max = 0;
        

        int i = 0, j = 0, ans = 0;

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
        i = 1;
        int cur_id;
        int count = 1;
        for(i = 0; i < l-1; ++i){
            //cout << next[i].first<<endl;
            j = 1;
            cur_id = i;
            while(1){
                if(j % 2 == 1){
                    cur_id = next[cur_id].first;
                }else{
                    cur_id = next[cur_id].second;
                }
                if(cur_id == -1)
                    break;
                if(cur_id == l-1){
                    count += 1;
                    break;
                }
                ++j;
            }
        }
        return count;


        






    }
};
