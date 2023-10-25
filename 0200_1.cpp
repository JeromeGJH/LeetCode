class Solution {
public:
    int row;
    int col;
    vector<vector<bool>> dp;
    queue<int> g;
    void check(vector<vector<char>>& grid, int i, int j){
        if(dp[i][j]){
            return;
        }
        if(grid[i][j] == '1'){
            dp[i][j] = true;
        }else{
            return;
        }
        //cout <<i << " "<<j<<endl;
        
        //bool up = true, down = true, left = true, right = true;
        if(i > 0){
            g.push(i-1);
            g.push(j);
        }
        if(i < row-1){
            g.push(i+1);
            g.push(j);
        }
        if(j > 0){
            g.push(i);
            g.push(j-1);
        }
        if(j < col-1){
            g.push(i);
            g.push(j+1);
        }
        int index1, index2;
        while(!g.empty()){
            index1 = g.front();
            g.pop();
            index2 = g.front();
            g.pop();
            check(grid, index1, index2);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        dp = vector<vector<bool>>(row, vector<bool>(col, false));
        int i, j;
        int count = 0;
        //cout <<"here1"<<endl;
        
        for(i = 0; i < row; ++i){
            for(j = 0; j < col; ++j){
                //cout <<i << " "<<j<<endl;
                if(grid[i][j] == '0' || dp[i][j]){
                    continue;
                }else{
                    //cout <<"here2"<<endl;
                    count += 1;
                    //dp[i][j] = count;
                    //cout <<"here3"<<endl;
                    check(grid, i, j);
                    //cout <<"here4"<<endl;
                }
            }
        }
        return count;
    }
};
