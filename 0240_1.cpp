class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0][0] > target){
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        if(matrix[m-1][n-1] < target){
            return false;
        }
        int low = 0,high = m-1,left = 0, right = n-1;
        int mid1, mid2, i, mid, l, h;
        while(low < high){
            mid1 = (low + high) / 2 + 1;
            if(matrix[mid1][0] > target){
                high = mid1 - 1;
            }else{
                low = mid1;
            }
        }
        h = low;
        
        low = 0, high = m-1;
        while(low < high){
            mid2 = (low + high) / 2;
            if(matrix[mid2][n-1] < target){
                low = mid2 + 1;
            }else{
                high = mid2;
            }
        }
        l = high;

        for(i = l; i <= h; ++i){
            left = 0;
            right = n-1;
            while(left <= right){
                mid = (left + right) / 2;
                if(matrix[i][mid] == target){
                    return true;
                }
                if(matrix[i][mid] > target){
                    right = mid -1;
                }else{
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};
