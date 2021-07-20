class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);
        int i = 0, m = updates.size();
        for(i = 0; i < m; ++i){
            arr[updates[i][0]] += updates[i][2];
            if(updates[i][1] <= length-2){
                arr[updates[i][1]+1] -= updates[i][2];
            }
        }
        for(i = 1; i < length; ++i){
            arr[i] += arr[i-1];
        }
        return arr;
    }
};
