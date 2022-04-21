class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low=0, high = m - 1;
        int mid;
        if(matrix[0][0] > target){
            return false;
        }
        while(low < high){
            mid = (low + high)/2 + 1;
            if(matrix[mid][0] > target){
                high = mid - 1;
            }else{
                if(matrix[mid][0] < target){
                    low =mid;
                }else{
                    return true;
                }
            }
        }
        //cout << "here1";
        int left = 0, right =n-1;
        while(left <= right){
            mid = (left + right)/2;
            if(matrix[low][mid] == target){
                return true;
            }
            if(matrix[low][mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
    }
};
