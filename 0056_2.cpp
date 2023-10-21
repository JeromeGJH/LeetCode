class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len =  intervals.size();
        if(len == 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 0;
        vector<vector<int>> res;
        //res.emplace_back(intervals[0]);
        for(i = 0; i < len; ++i){
            int l = intervals[i][0], r = intervals[i][1];
            for(j = i+1; j < len; ++j){
                if(r >= intervals[j][0]){
                    r = max(intervals[j][1], r);
                    i = j;
                }else{
                    break;
                }
            }
            res.emplace_back(vector<int>({l, r}));
            
        }
        return res;

    }
};
