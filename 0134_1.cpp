class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        if(len == 1){
            return 0;
        }
        int g = 0;
        vector<int> dp(len,0);
        int i = 0;
        for(i = 0; i< len; ++i){
            dp[i] = gas[i] - cost[i];
        }
        i = 0;
        int start = 0;
        int cur = 0;

        for(i = 0; i < len; ++i){
            cout << "here1" << endl;
            // if(i == len){
            //     break;
            // }
            if(dp[i] < 0){
                cout << "here2" << endl;
                continue;
            }else{
                cout << "here3" << endl;
                start = i;
                cur = (i+1)%len;
                g = dp[i];
                while(cur != start){
                    cout << "here4" << endl;
                    cout << cur <<endl;
                    g += dp[cur];
                    if(g < 0){
                        break;
                    }
                    cur =  (cur+1)%len;
                }
                if(cur == start){
                    return start;
                    // cout << "here5" << endl;
                    // return start;
                }
            }
        }
        cout << "loop ends" << endl;
        cout << start << " " << cur << endl;
        if(cur == start){
            cout << "here5" << endl;
            return start;
        }
        cout << "loop ends" << endl;
        return -1;
    }
};
