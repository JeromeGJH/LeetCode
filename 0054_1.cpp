class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
        int t = 0, b = row-1, l = 0, r = col-1;
        int i = 0, j = 0;
        bool ifHor = true;
        
        while(true){
            
            if(ifHor){
                if(i < (row+1)/2){
                    for(j = l; j <= r; ++j){
                        res.emplace_back(matrix[i][j]);
                    }
                    j = r;
                    t += 1;

                }else{
                    for(j = r; j >=l; --j){
                        res.emplace_back(matrix[i][j]);
                    }
                    j = l;
                    b -= 1;
                }
                ifHor = false;

            }else{
                if(j < col/2){
                    for(i = b; i >= t; --i){
                        res.emplace_back(matrix[i][j]);

                    }
                    i = t;
                    l += 1;
                }else{
                    for(i = t; i <= b; ++i){
                        res.emplace_back(matrix[i][j]);
                    }
                    i = b;
                    r -= 1;
                }

                ifHor = true;

            }
            if(t > b || l > r ){
                break;
            }
        }
        return res;
    }
};
