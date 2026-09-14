class MinStack {
private:
    std::vector<std::pair<int, int>> container;
public:
    MinStack() {
        container.reserve(32);
    }
    
    void push(int val) {
        if (!container.empty()) container.emplace_back(val, std::min(container.back().second, val));
        else container.emplace_back(val, val);
    }
    
    void pop() {
        container.pop_back();
    }
    
    int top() {
        return container.back().first;
    }
    
    int getMin() {
        return container.back().second;
    }
};
