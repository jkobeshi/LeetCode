class MinStack {
private:
    priority_queue<int, vector<int>, greater<int>> mins;
    unordered_map<int, int> owns;
    stack<int> stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        mins.push(val);
        owns[val]++;
    }
    
    void pop() {
        if(!stk.empty()){
            int temp = stk.top();
            stk.pop();
            owns[temp]--;
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        while(owns[mins.top()] == 0){
            mins.pop();
        }
        return mins.top();
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