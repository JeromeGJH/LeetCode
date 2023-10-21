class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        if(len == 0){
            intervals.emplace_back(newInterval);
            return intervals;
        }
        int i = 0;
        int start = -1;
        int cnt = 0;
        int l = newInterval[0], r = newInterval[1];
        for(i = 0; i < len; ++i){
            //cout << l << " " << r << endl;
            if(r < intervals[i][0]){
                start = i;
                break;
            }
            if(l > intervals[i][1]){
                start = i+1;
                continue;
            }else{
                start = i+1;
                 l = min(l, intervals[i][0]);
                 if(r <= intervals[i][1]){
                     r = intervals[i][1];
                     ++cnt;
                     break;
                 }else{
                     ++cnt;
                 }
            }
        }
        //cout <<"here1"<<endl;
        intervals.insert(intervals.begin()+start, vector<int>{l,r});
        if(cnt > 0){
            intervals.erase(intervals.begin()+start-cnt, intervals.begin()+start);
        }
        
        return intervals;


    }
};
