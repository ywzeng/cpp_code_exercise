class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int poped_num;
        if(!stack2.empty()) {
            poped_num = stack2.top();
            stack2.pop();
        } else if (!stack1.empty()) {
            while(!stack1.empty()) {
                int temp_num = stack1.top();
                stack1.pop();
                stack2.push(temp_num);
            }
            poped_num = stack2.top();
            stack2.pop();
        }
        return poped_num;
    }
    
    /** Get the front element. */
    int peek() {
        int peek_num;
        if(!stack2.empty()) {
            peek_num = stack2.top();
        } else if(!stack1.empty()) {
            while(!stack1.empty()) {
                int temp_num = stack1.top();
                stack1.pop();
                stack2.push(temp_num);
            }
            peek_num = stack2.top();
        }
        return peek_num;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(stack1.empty() && stack2.empty()) {
            return true;
        }
        return false;
    }

private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
