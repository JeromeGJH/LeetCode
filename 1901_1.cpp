class Solution {
public:
    int checkMax(vector<vector<int>>& mat, int row, int len){
        int index = 0;
        for(int i = 1; i < len; ++i){
                if(mat[row][i] > mat[row][index]){
                    index = i;
                }
            }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = m-1, mid;
        vector<int> max = vector<int>(m, -1);
        while(low < high){
            mid = (low + high) / 2;
            
            if(max[mid] < 0){
                max[mid] = checkMax(mat, mid, n);
            }
            if(mid + 1 < m && max[mid+1] < 0){
                max[mid+1] = checkMax(mat, mid+1, n);
            }
            if(mid - 1 >= 0 && max[mid-1] < 0){
                max[mid-1] = checkMax(mat, mid-1, n);
            }

            if(mid == 0){
                if(mat[0][max[0]] > mat[1][max[1]]){
                    return vector<int>{0, max[0]};
                }
            }

            if(mid == m-1){
                if(mat[m-1][max[m-2]] > mat[m-2][max[m-2]]){
                    return vector<int>{m-1, max[m-1]};
                }
            }
            
            if(mat[mid][max[mid]] <= mat[mid+1][max[mid+1]]){
                low = mid+1;
            }else{
                if(mat[mid][max[mid]] >= mat[mid-1][max[mid-1]]){
                    return vector<int>{mid, max[mid]};
                }else{
                    high = mid - 1;
                }
            }
        }
        
        return vector<int>{low, max[low]};
    }
};
