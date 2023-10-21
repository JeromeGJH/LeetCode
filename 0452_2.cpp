class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2){
        return v1[1] < v2[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        
        sort(points.begin(), points.end(), compare);

        int pos = points[0][1];
        int ans = 1;
        for (const vector<int>& balloon: points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
};
