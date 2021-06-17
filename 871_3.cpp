class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int num = stations.size();
        priority_queue<long> dp;
        int fuel = startFuel;
        int ans = 0, i = 0;
        while(fuel < target){
            while( i < num){
                if(fuel >= stations[i][0]){
                    dp.push(stations[i][1]);
                    ++i;
                }else{
                    break;
                }
            }
            if(!dp.empty()){
                fuel += dp.top();
                dp.pop();
                ++ans;
            }else{
                return -1;
            }
        }
        return ans;
    }
};
