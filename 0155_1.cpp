class MinStack {
public:
    stack<int> stack;
    vector<int> nums;
    int len;
    MinStack() {

    }
    
    void push(int val) {
        stack.push(val);
        int i = 0;
        len = nums.size();
        if(len == 0){
            nums.emplace_back(val);
            return;
        }
        for(i = 0; i < len; ++i){
            if(nums[i] >= val){
                //cout << "here1" << endl;
                nums.insert(nums.begin() + i, val);
                break;
            }
        }
        if(i == len){
            nums.emplace_back(val);
        }
    }
    
    void pop() {
        int num = stack.top();
        for(int i = 0; i < len; ++i){
            if(nums[i] == num){
                nums.erase(nums.begin()+i, nums.begin()+i+1);
                break;
            }
        }
        stack.pop();

    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return nums[0];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
