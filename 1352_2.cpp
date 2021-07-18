class ProductOfNumbers {
public:
    vector<int> dp;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num ==0){
            dp.clear();
        }else{
            if(dp.empty()){
                dp.push_back(num);
            }else{
                dp.push_back(dp.back() * num);
            }
        }
    }
    
    int getProduct(int k) {
        if(k > dp.size()){
            return 0;
        }else{
            if(k == dp.size()){
                return dp.back();
            }else{
                return dp[dp.size()-1] / dp[dp.size()-k-1];
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
