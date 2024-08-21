class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {}

    void push(int x) {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        // Insert the desired element in the stack input
        input.push(x);
        // Pop out elements from the stack output and push them into the stack
        // input
        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }
    }

    int pop() {
        int val = input.top();
        input.pop();
        return val;
    }

    int peek() { return input.top(); }

    bool empty() { return input.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */