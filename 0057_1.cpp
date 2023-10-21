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
            if(l > intervals[i][1] || r < intervals[i][0]){
                //cout <<"here2"<<endl;

                if( r < intervals[i][0]){
                    if(start < 0){
                        start = i;
                    }
                    break;

                }
                if(l > intervals[i][1]){
                    start = i + 1;
                    continue;
                }
                continue;
            }else{
                //cout <<"here3"<<endl;
                if(start < 0){
                    start = i;
                }
                cnt += 1;
                if(l < intervals[i][0]){
                    if(r <= intervals[i][1]){
                        r = intervals[i][1];
                        break;
                    }else{
                        continue;
                    }
                }else{
                    l = intervals[i][0];
                    if(r <= intervals[i][1]){
                        r = intervals[i][1];
                        break;
                    }else{
                        continue;
                    }
                }
            }
        }
        //cout <<"here1"<<endl;
        if(cnt > 0){
            intervals.erase(intervals.begin()+start, intervals.begin()+start + cnt);
        }
        intervals.insert(intervals.begin()+start, vector<int>{l,r});
        return intervals;


    }
};
