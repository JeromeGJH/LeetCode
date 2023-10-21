class MinStack {
public:
    stack<int> stack;
    std::stack<int> min;
    MinStack() {

    }
    
    void push(int val) {
        if(stack.empty()){
            stack.push(val);
            min.push(val);
            return;
        }else{
            if(val < min.top()){
                min.push(val);
            }else{
                min.push(min.top());
            }
            stack.push(val);
        }
        return;
    }
    
    void pop() {
        
        stack.pop();
        min.pop();

    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return min.top();
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
