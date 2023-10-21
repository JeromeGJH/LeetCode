class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
        if(len == 1){
            return 1;
        }
        sort(points.begin(), points.end());
        int i = 0, ans = 0, j;
        for(i = 0; i < len; ++i){
            ans += 1;
            int l = points[i][0];
            int r = points[i][1];
            for(j = i+1; j < len; ++j){
                if(r < points[j][0]){
                    i = j-1;
                    break;
                }else{
                    l = points[j][0];
                    r = min(r, points[j][1]);
                    i = j;
                }
            }
        }
        return ans;

    }
};
