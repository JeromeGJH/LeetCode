class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int num = stations.size();
        priority_queue<long> dp;
        int fuel = startFuel;
        int ans = 0, i = 0;
        while(fuel < target){
            while( i < num && fuel >= stations[i][0])
                dp.push(stations[i++][1]);
            if(dp.empty()) 
                return -1;
            fuel += dp.top();
            dp.pop();
            ++ans;
        }
        return ans;
    }
};
