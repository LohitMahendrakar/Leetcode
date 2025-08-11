class MinStack {
public:
    queue<int> queue1, queue2;
    MinStack() {}

    void push(int val) {
        // Move all elements from queue2 to queue1
        while (!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }

        // Add new element to queue2
        queue2.push(val);

        // Move all elements back to queue2
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
    }

    void pop() { queue2.pop(); }

    int top() { return queue2.front(); }

    int getMin() {
        int mn = INT_MAX;
        queue<int> temp = queue2;
        while (!temp.empty()) {
            mn = min(mn, temp.front());
            temp.pop();
        }
        return mn;
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