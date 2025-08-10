#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> queue1, queue2;

    MyStack() {}

    void push(int x) {
        // Move all elements from queue2 to queue1
        while (!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }

        // Add new element to queue2
        queue2.push(x);

        // Move all elements back to queue2
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
    }

    int pop() {
        int val = queue2.front();
        queue2.pop();
        return val;
    }

    int top() {
        return queue2.front();
    }

    bool empty() {
        return queue2.empty();
    }
};
