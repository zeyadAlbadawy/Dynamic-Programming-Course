class MinStack {
public:
    vector<pair<int, int>> res;
    MinStack() {
        
    }
    
    void push(int val) {
       if(res.empty()) res.push_back({val, val});
       else res.push_back({val, min(val, res[res.size() - 1].second)});
    }
    
    void pop() {
        res.pop_back();
    }
    
    int top() {
        return res[res.size() - 1].first;
    }
    
    int getMin() {
        return res[res.size() - 1].second;
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