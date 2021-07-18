class ProductOfNumbers {
public:
    vector<vector<int>> dp;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(dp.empty()){
            if(num == 0){
                dp.push_back(vector<int>{num, 0});
            }else{
                dp.push_back(vector<int>{num, 1});
            }
        }else{
            if(num == 0){
                dp.push_back(vector<int>{0, 0});
            }else{
                if(dp.back()[1] == 0){
                    dp.push_back(vector<int>{num, 1});
                }else{
                    dp.push_back(vector<int>{num * dp.back()[0], dp.back()[1] + 1});
                }
            }
        }
    }
    
    int getProduct(int k) {
        if(k > dp.back()[1]){
            return 0;
        }else{
            if(k == dp.back()[1]){
                return dp.back()[0];
            }else{
                return dp[dp.size()-1][0] / dp[dp.size()-k-1][0];
            }
        }
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
